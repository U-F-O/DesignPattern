#include "Header.h"

class FileBase{
    
public:
    virtual void CopyFile() = 0;
    
};

class FileManager : public FileBase{
    
public:
    void CopyFile(){
        cout << "I'm coping file" << endl;
    }
    
};

class FileProxy : public FileBase{
    
    FileManager * file;
    
public:
    
    FileProxy(FileManager* file){
        this -> file = file;
    }
    
    void CopyFile(){
        cout << "This is File Proxy: ";
        file->CopyFile();
    }
};


class ProxyTest{
    
public:
    
    static void test(){
        
        FileManager *filemanager = new FileManager;
        filemanager->CopyFile();
        
        FileProxy* fileproxy = new FileProxy(filemanager);
        fileproxy->CopyFile();
    }
};

