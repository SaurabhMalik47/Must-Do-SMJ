/*
Problem:
You are given a string 'S' which contains all lowercase characters without any punctuation marks. 
Return the internet resource address for the given string.

Internet source address for a string is defined as:
<protocol>://<domain>.ru[/<context>]
where,
<protocol> can either be http of ftp.
<domain name> is a string consisting of lowercase english characters.
<context> is a non empty string consisting of lowercase english characters.

Input:
httpsunrux
ftphttprururu
httprrur

Output:
http://sun.ru/x
ftp://http.ru/ruru
http://r.ru/r


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

int getRest(string s, int i) 
{ 
     for(int j=i+1; j<s.length(); j++)
     {
        if(s[j] == 'r' && s[j+1] == 'u')
           return j-i-1; 
     }
     return -1; 
}

void internetAddress(string s) 
{
     int starter, pos;
    
     if(s[0] == 'h' && s[1] == 't' && s[2] == 't' && s[3] == 'p') 
     { 
          cout<<"http://"; 
          starter = 3; 
          pos = getRest(s, 3);
          cout << s.substr(starter+1, starter+pos-3);
     } 
    
     else 
     { 
         cout<<"ftp://";
         starter = 2;
         pos = getRest(s, 2);
         cout << s.substr(starter+1, starter+pos-2);
     } 
    
     cout << ".ru"; 
     pos = starter + pos + 2; 
     cout << "/"; 
     cout << s.substr(pos+1);
}
