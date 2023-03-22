#include "debug_log.h"
#include "GBN.h"
#include <iostream>
void print_debug(int type, string content)
{
	string printout = "";
	switch (type)
	{
	case DEBUG_INFO:
		printout += "<INFO>\t\t";
		break;
	case DEBUG_ERROR:
		printout += "<ERROR>\t\t";
		break;
	case DEBUG_RECV:
		printout += "<RECV>\t\t";
		break;
	case DEBUG_SEND:
		printout += "<SEND>\t\t";
		break;
	default:
		printout += "<UNKNOWN>\t";
		break;
	}
	printout += content;
	cout << printout << endl;
	return;
}

void print_debug_sorv(int type, char flags, int length, unsigned short seq)
{
	string printout = "";
	switch (type)
	{
	case DEBUG_RECV:
		printout += "<RECV>\t\t";
		break;
	case DEBUG_SEND:
		printout += "<SEND>\t\t";
		break;
	default:
		printout += "<UNKNOWN>\t";
		break;
	}
	printout += "flags : ";
	if (flags & ACK) { printout += " ACK "; }
	if (flags & SYN) { printout += " SYN "; }
	if (flags & FIN) { printout += " FIN "; }
	if (flags & SEN) { printout += " SEN "; }
	if (flags & NAK) { printout += " NAK "; }
	if (flags & FINAL) { printout += " FINAL "; }
	printout += " | ";
	printout += " length : ";
	if (type == DEBUG_RECV) { cout << printout << length << " | seq : " << seq << endl; }
	else { cout << printout << length << " | ack : " << seq << endl; }
	return;
}