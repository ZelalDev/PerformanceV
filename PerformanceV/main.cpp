//
//  main.cpp
//  PerformanceV
//
//  Created by Zelal Aydın on 31.03.2026.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {


    ifstream document(argv[1]);
    if (!document.is_open()) {
        cout << "file couldn't opened: " << argv[1] << endl;
        return 1;
    }

    string line;
    
    // Counters for instruction types
    int arithmeticCount = 0;
    int logicalCount = 0;
    int memoryCount = 0;
    int branchCount = 0;
    int otherCount = 0;

    int totalCycles = 0;
    int totalInst = 0;

    // reading file line by line
    while (getline(document, line)) {
        
        // cleaning comments
        int hashPos = line.find('#');
        if (hashPos != -1) {
            line = line.substr(0, hashPos);
        }

        // cleaning labels
        int colonPos = line.find(':');
        if (colonPos != -1) {
            line = line.substr(colonPos + 1);
        }

        // finding operator
        string op = "";
        int i = 0;
        
        // passing spaces
        while (i < line.length() && (line[i] == ' ' || line[i] == '\t')) {
            i++;
        }
        
        // get the first word as an instruction
        while (i < line.length() && line[i] != ' ' && line[i] != '\t') {
            op += line[i];
            i++;
        }

        // if the line is only space then pass
        if (op == "") {
            continue;
        }

        totalInst++;

        // Finding the type and matching
        if (op == "add" || op == "addi" || op == "sub" || op == "mul" || op == "div" || op == "rem" || op == "li" || op == "mv") {
            arithmeticCount++;
            totalCycles += 1;
        }
        else if (op == "and" || op == "andi" || op == "or" || op == "ori" || op == "xor" || op == "xori" || op == "sll" || op == "slli" || op == "srl" || op == "srli" || op == "sra" || op == "srai") {
            logicalCount++;
            totalCycles += 1;
        }
        else if (op == "lw" || op == "lh" || op == "lb" || op == "sw" || op == "sh" || op == "sb" || op == "ld" || op == "sd") {
            memoryCount++;
            totalCycles += 2;
        }
        else if (op == "beq" || op == "bne" || op == "blt" || op == "bge" || op == "bltu" || op == "bgeu" || op == "j" || op == "jal" || op == "jalr" || op == "ret" || op == "call" || op == "ble" || op == "bgt") {
            branchCount++;
            totalCycles += 3;
        }
        else {
            otherCount++;
            totalCycles += 1; // Default cycle
        }
    }

    // output
    cout << "\n===== INSTRUCTION MIX =====" << endl;
    cout << "Total instruction: " << totalInst << "\n" << endl;

    // print if count>0
    if (arithmeticCount > 0) {
        int percentage = (arithmeticCount * 100) / totalInst;
        cout << "ARITHMETIC: " << arithmeticCount << " piece (" << percentage << "%)" << endl;
    }
    if (logicalCount > 0) {
        int percentage = (logicalCount * 100) / totalInst;
        cout << "LOGICAL: " << logicalCount << " piece (" << percentage << "%)" << endl;
    }
    if (memoryCount > 0) {
        int percentage = (memoryCount * 100) / totalInst;
        cout << "MEMORY: " << memoryCount << " piece (" << percentage << "%)" << endl;
    }
    if (branchCount > 0) {
        int percentage = (branchCount * 100) / totalInst;
        cout << "BRANCH: " << branchCount << " piece (" << percentage << "%)" << endl;
    }
    if (otherCount > 0) {
        int percentage = (otherCount * 100) / totalInst;
        cout << "OTHER: " << otherCount << " piece (" << percentage << "%)" << endl;
    }

    // CPI calculating and printing
    double cpi = (double)totalCycles / totalInst;
    
    cout << "\n===== CPI SUMMARY =====" << endl;
    cout << "Total cycle : " << totalCycles << endl;
    cout << "Average CPI : " << cpi << endl;
    cout << "=====================" << endl;

    document.close();
    return 0;
}
