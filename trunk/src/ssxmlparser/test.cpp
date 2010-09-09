#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "ssxmlparser.h"


string xml;
string element; 
string tag;


void readXmlFromFile(string &result)
{
	int length;
	char * buffer;
	
	ifstream is;
	is.open ("test.txt", ios::binary );
	
	// get length of file:
	is.seekg (0, ios::end);
	length = is.tellg();
	is.seekg (0, ios::beg);
	
	// allocate memory:
	buffer = new char [length];
	
	// read data as a block:
	is.read (buffer,length);
	is.close();
	
	
	result = buffer;
	
	delete[] buffer;
	
}

void test_ssxmlp_extract_one_element(void)
{
	if (ssxmlp_extract_one_element(xml, tag, element) < 0)
		cout << "error in: " << "ssxmlp_extract_one_element" << endl;
	else
		cout << "element extracted: \n" << element << endl;
}


void test_ssxmlp_extract_all_elements(void)
{
	list<string> result;
	list<string>::iterator it;
	
	ssxmlp_extract_all_elements(xml, tag, result);
	
	for(it = result.begin(); it != result.end(); ++it){
		cout << "\t\tElement: \n" << (*it) << endl;		
	}
	
}



void test_ssxmlp_parse_element(void)
{
	list<string> eParse;
	list<string> results;
	list<string>::iterator it;
	string aux = "Mensaje";
	
	if(ssxmlp_parse_element(xml, aux , eParse, results) < 0){
		cout << "ERROR ssxmlp_parse_element \n";
		return;
	}
			      
	
	for(it = eParse.begin(); it != eParse.end(); ++it){
		cout << "Element parsed:" << (*it) << endl;		
	}
	for(it = results.begin(); it != results.end(); ++it){
		cout << "Value of Element parsed: \n" << (*it) << endl;		
	}
	
}



void test_ssxmlp_create_element(void)
{
	list<string> eParse;
	list<string> results;
	list<string>::iterator it;
	string aux = "Mensaje", result = "";
	
	ssxmlp_parse_element(xml, aux , eParse, results);
	
	if(ssxmlp_create_element(aux, eParse, results, result) < 0){
		cout << "ERROR ssxmlp_parse_element \n";
		return;
	}
	
	
	cout << "This element was created: \n\n" << result << endl;
}

int main (void)
{
	element = ""; 
	tag = "Destinatario";
	
	
	readXmlFromFile(xml);
	
	/*!done
	test_ssxmlp_extract_one_element()
	*/
	/*! done
	test_ssxmlp_extract_all_elements();
	*/
	/*! done 
	test_ssxmlp_parse_element();
	*/
	/*! done :)
	test_ssxmlp_create_element();
	*/
	return 0;
}	