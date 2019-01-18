#include<bits/stdc++.h>
#include <dirent.h>
#include <sys/types.h>
#include <process.h>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void display(string filepath)
{
    string getcontent;
    ifstream openfile;
    openfile.open(filepath.c_str(),ios::in);
    if(openfile.is_open())
    {
        while(! openfile.eof())
        {
            openfile >> getcontent;
            cout << getcontent << endl;
        }
    }
    for(int i=0;i<600000000;i++){}
}

void printdir(char DESTINATION_FOLDER[],char SOURCE_FOLDER[])
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    struct tm      *tm;

    char src_folder[1024];
    char dest_folder[1024];
    char *filen;
    int nf;
    cout<<"Enter length of filename : ";
    cin>>nf;
    filen = new char[nf];
    cout<<"Enter filename : ";
    cin>>filen;
    cout<<filen;
    if((dp = opendir(SOURCE_FOLDER)) == NULL) {
         fprintf(stderr,"cannot open directory: %s\n", SOURCE_FOLDER);
         return;
    }
    chdir(SOURCE_FOLDER);
    stat(filen,&statbuf);

    if(!S_ISDIR(statbuf.st_mode))
    {
         sprintf(src_folder,"%s%s", SOURCE_FOLDER,filen);
         sprintf(dest_folder,"%s%s", DESTINATION_FOLDER,filen);
         cout<<filen<<"----------------"<<dest_folder<<endl;

         rename(src_folder, dest_folder);
    }
    chdir("..");
    closedir(dp);
}

void crfile(const char *path){
   fstream file;
   file.open(path,ios::out);
   if(!file)
   {
       cout<<"Error in creating file!!!";
   }
   cout<<"File created successfully.";
   file.close();
}
void list_dir(const char *path) {
   struct dirent *entry;
   DIR *dir = opendir(path);

   if (dir == NULL) {
        cout << "Wrong Directory"<<endl;
      return;
   }
   while ((entry = readdir(dir)) != NULL) {
   cout << entry->d_name << endl;
   }
   closedir(dir);
}

int main()
{
    string dir ="C:/Users/Lenovo/Desktop/ishita/internity/";
    while(true){
        system("cls");
        cout <<dir<<endl;
        list_dir(dir.c_str());
        string str;
        cout <<"\n"<< dir<<" ";
        getline(cin,str);
        while(str.length()==0)
            getline(cin,str);
        stringstream ss(str);
        string comm,ffo;
        ss >> comm;
        ss >> ffo; //To move file add
        if(comm=="cd"){//change directory
            dir=ffo;
        }
        else if(comm=="forward"){//select folder
            dir+=ffo;
        }
        else if(comm=="back"){
            int index=-1;
            ffo="";
            int flag=0;
            for(int i=dir.length()-1;i>=0;i--){
                if(dir[i]=='/'){
                    if(flag==0){flag=1;}
                    else{index=i;break;}
                }
            }
            for(int i=0;i<=index;i++){
                    ffo+=dir[i];}

            dir=ffo;
        }
        else if(comm=="makefol"){
            string newf=dir+ffo;
            mkdir(newf.c_str());
            cout << "Directory created\n";
            for(int i=0;i<600000000;i++){}
        }
        else if(comm=="delfol"){
            string newf=dir+ffo;
            if(rmdir(newf.c_str())==0){
                cout << "Directory deleted\n";
            }
            else{
                cout<<"Unable to delete"<<endl;
            }
            for(int i=0;i<600000000;i++){}
        }
        else if(comm=="quit"){
                break;}
        else if(comm=="delfile"){
                string newf=dir+ffo;
            if (remove(newf.c_str()) == 0)
                printf("Deleted successfully");
            else
                printf("Unable to delete the file");
            for(int i=0;i<600000000;i++){}
        }
        else if(comm=="makefile"){
            string newf=dir+ffo;
            crfile(newf.c_str());
            for(int i=0;i<600000000;i++){}
        }
        else if(comm=="editfile")
        {
            fstream filea;
            string dataadded;
            string filepath=dir+ffo;
            filea.open(filepath.c_str(),ios::app);

            if (filea == NULL)
            {
                printf("\nUnable to open '%s' file.\n", filepath.c_str());
                continue;
            }

            printf("\nEnter data to append: ");
            getline(cin,dataadded);
            filea << dataadded;

            printf("\nSuccessfully appended data to file. \n");
            filea.close();
            display(filepath);

        }
        else if(comm=="movefile")
        {
            //cin.ignore();
            //cin.clear();
            string ss,dd;
            cout<<"\nEnter source address: \n";
            cin>>ss;
            //cout<<ss<<endl;
            cout<<"\nEnter destination address: \n";
            cin>>dd;
            int ns = ss.length(),nd = dd.length();
            char ar1[ns+1];
            char ar2[nd+1];
            strcpy(ar1, ss.c_str());
            strcpy(ar2, dd.c_str());
            //cout<<endl<<ar2<<endl;
            //cout<<ar1;
            printdir(ar2,ar1);
            for(int i=0;i<600000000;i++){}
        }
        else if(comm== "renamefile")
        {
            string ss,dd;
            cout<<"\nEnter old name: \n";
            cin>>ss;
            cout<<"\nEnter new name: \n";
            cin>>dd;
            int ns = ss.length(),nd = dd.length();
            char ar1[ns+1];
            char ar2[nd+1];
            strcpy(ar1, ss.c_str());
            strcpy(ar2, dd.c_str());

            int xy = rename(ar1,ar2);
            if(xy==0)
                cout<<"\nRenamed successfully. \n";
            else
                cout<<"\nError\n";
        }


    }

}
