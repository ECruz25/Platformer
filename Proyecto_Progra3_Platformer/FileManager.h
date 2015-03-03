#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

class FileManager
{
    private:
        enum LoadType { Attributes, Contents };
        int type;
        bool identifier_found;
        vector<string> temp_attributes, temp_contents;

    public:
        FileManager();
        virtual ~FileManager();

        void LoadContent(const char *filename,
                            vector<vector<string> > &attributes,
                            vector<vector<string> > &contents);
        void LoadContent(const char *filename,
                            vector<vector<string> > &attributes,
                            vector<vector<string> > &contents,
                            string identifier);
};

#endif // FILEMANAGER_H
