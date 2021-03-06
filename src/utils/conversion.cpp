/* This file is part of the Springlobby (GPL v2 or later), see COPYING */

#include "conversion.h"

#include <wx/arrstr.h>
#include <wx/tokenzr.h>
#include <sstream>
#include <algorithm>

StringtokenizerVectorized::StringtokenizerVectorized( wxStringTokenizer tokenizer )
{
    reserve( tokenizer.CountTokens() );
    while ( tokenizer.HasMoreTokens() )
        push_back( tokenizer.GetNextToken() );
}

std::string stdprintf(const char* format, ...)
{
	char buf[1024];
	va_list args;
	va_start(args, format);
	int count = vsnprintf(buf, 1024, format, args);
	va_end(args);
	return std::string(buf, count);
}

wxString TowxString(const std::string& arg){
  std::stringstream s;
  s << arg;
  return wxString(s.str().c_str(),wxConvUTF8);
}

wxString TowxString(int arg){
  std::stringstream s;
  s << arg;
  return wxString(s.str().c_str(),wxConvUTF8);
}

long FromwxString(const wxString& arg){
  std::stringstream s;
  s << STD_STRING(arg);
  int64_t ret;
  s >> ret;
  return ret;
}


std::string strtolower(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}
