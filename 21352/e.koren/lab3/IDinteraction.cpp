#include <iostream>
#include <unistd.h>
void printID(){
        std::cout<<"Real user ID: "<<getuid()<<std::endl;
        std::cout<<"Effective User ID: "<< geteuid()<<std::endl;
        return;
}

void openFile(char* fileName){
        FILE* file = fopen(fileName,"r");
        if (file ==NULL){
                perror("unable to open the file.\n");
        }
        else{
                std::cout<<"file opened succefully!"<<std::endl;
                if (fclose(file)==EOF){
                        perror("unable to close the file.\n");
                }
        }
        return;
}

void setID(){
        if (seteuid(getuid()==-1)){
                perror("unable to set ID\n");
                }
        else{
                std::cout<<"set id sucessfully!"<<std::endl;
        return;
        }
}
int main(int argc,char* argv[]){

        printID();
        setID();
        if(argc==2){
                openFile(argv[1]);
        }
}

