/*
** EPITECH PROJECT, 2023
** NanoTekSpice.cpp
** File description:
** NanoTekSpice
*/

#include <signal.h>
#include <thread>
#include <chrono>
#include "Circuit.hpp"
#include "Parser.hpp"

static const int ERROR = 84;
static const int SUCCESS = 0;
static bool sigint;

static void handler(int s){
	(void)s;
	sigint = true;
}

static void set_handler(void) {
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = handler;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);
}

static void assignemnt(Circuit &circuit, const std::string &cmd) {
    bool validComponent = false;
	std::string name = cmd.substr(0, cmd.find('='));
	std::string value = cmd.substr(cmd.find('=') + 1);
    for (const auto& pair : circuit._listComponents) {
        if (pair.first == name)
            validComponent = true;
    }
	if (!validComponent || (circuit.getComponent(name)->getType() != "input" &&
    circuit.getComponent(name)->getType() != "clock") || value.length() > 1)
		throw Exception("Error: invalid assignment");
	if (value == "0") circuit.getComponent(name)->setNextState(FALSE);
	else if (value == "1") circuit.getComponent(name)->setNextState(TRUE);
	else if (value == "U") circuit.getComponent(name)->setNextState(UNDEFINED);
	else throw Exception("Error: invalid assignment");
}

static void readInput(Circuit &circuit) {
    std::string cmd;
    while (1) {
        sigint = false;
        std::cout << "> ";
        if (!std::getline(std::cin, cmd) || cmd == "exit") break;
        else if (cmd == "display") circuit.display();
        else if (cmd == "simulate") circuit.simulate(1);
        else if (cmd == "loop") {
            while (!sigint) { circuit.simulate(1); circuit.display(); }
		    sigint = false;
        } else if (cmd.find('=') != std::string::npos)
            assignemnt(circuit, cmd);
        else std::cerr << " " << cmd << " is not a valid command" << std::endl;
    }
}

int NanoTekSpice(int ac, char **av) {
    try {
        if (ac != 2) throw Exception("Error: invalid numbers of arguments");
        Parser parser(av[1]);
        Circuit circuit(parser.GetChipsets(), parser.GetLinks());
        set_handler();
        readInput(circuit);
        return (SUCCESS);
    } catch(Exception &e) {
        std::cerr << e.what() << std::endl;
        return (ERROR);
    }
}
