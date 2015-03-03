#include "FileManager.h"

FileManager::FileManager()
{
    identifier_found = false;
}

FileManager::~FileManager()
{
    //dtor
}

void FileManager::LoadContent(const char *filename,
                                vector<vector<string> > &attributes,
                                vector<vector<string> > &contents)
{
    string line, new_line;
    ifstream openfile(filename);
    if(openfile.is_open())
    {
        while(!openfile.eof())
        {
            stringstream str;
            getline(openfile, line);

            if(line.find("Load=") != string::npos)
            {
                type = Attributes;
                line = line.erase(0, line.find("=") + 1);
                temp_attributes.clear();
            }
            else
            {
                type = Contents;
                temp_contents.clear();
            }

            str<<line;

            while(getline(str, new_line, ']'))
            {
                new_line.erase(remove(new_line.begin(), new_line.end(), '['), new_line.end());
                string erase_ = "\t\n\r";
                new_line.erase(new_line.find_last_not_of(erase_)+1);
                if(type == Attributes)
                {
                    temp_attributes.push_back(new_line);
                }
                else
                {
                    temp_contents.push_back(new_line);
                }
                cout<<new_line<<endl;
            }
            if(type == Contents && temp_contents.size() > 0)
            {
                attributes.push_back(temp_attributes);
                contents.push_back(temp_contents);
            }
        }
    }
    else
    {
    }
}
