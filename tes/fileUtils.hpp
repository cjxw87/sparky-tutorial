//
//  fileUtils.hpp
//  tes
//
//  Created by xiaoweiwu on 3/13/16.
//  Copyright © 2016 xiaoweiwu. All rights reserved.
//
#pragma once



#ifndef fileUtils_h
#define fileUtils_h

#include <string>
#include <fstream>
namespace sparky {
    
    class FileUtils
    {
    public:
        static std::string read_file(const char* filepath)
        {
            FILE* file = fopen(filepath, "rt");
            fseek(file, 0, SEEK_END);
            unsigned long length = ftell(file);
            char* data = new char[length + 1];
            memset(data, 0, length + 1);
            fseek(file, 0, SEEK_SET);
            fread(data, 1, length, file);
            fclose(file);
            
            std::string result(data);
            delete[] data;
            return result;
        }
    };
    
}

#endif



