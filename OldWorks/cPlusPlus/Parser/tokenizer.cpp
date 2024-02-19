#include "tokenizer.h"


void Tokenizer::Tokenize(const string& _line)
{
	size_t pos = _line.find_first_of(m_delimiters);
	size_t start = 0;
	size_t len;
	
	while(pos!=string::npos) {
		len = pos - start;
		if(len>0) {
			m_queue.push(_line.substr(start,len));
		}
		if(!isspace(_line[pos])) {
			m_queue.push(_line.substr(pos,1));
		}
		start = pos+1;
		pos =  _line.find_first_of(m_delimiters,pos+1);
	}	

	if(!isspace(_line[start]) && _line[start]!='\0') {
		if(isspace(_line[_line.size()-1])) {
			m_queue.push(_line.substr(start,_line.size()-1-start));	
		} else {
			m_queue.push(_line.substr(start,_line.size()-start));
		}	
	}

}

