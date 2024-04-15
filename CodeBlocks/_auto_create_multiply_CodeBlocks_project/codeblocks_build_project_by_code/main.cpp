#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <direct.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <direct.h>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <regex>
using namespace std;
#define ll long LONG_MAX
const int maxn=1e5+10;
const int max_path_len=256;
const int max_len=1e4+10;

vector<string> list_project_name;

void set_list_project_name(vector<string> & vec)
{
    for (auto d:vec)
        list_project_name.push_back(d);
}

void set_vector_string(int l, int r)
{
    int i;
    vector<string> vec;
    for (i=l;i<=r;i++)
        vec.push_back(to_string(i));
    set_list_project_name(vec);
}

void set_vector_string_character(char l,char r)
{
    int i;
    stringstream ss;
    vector<string> vec;
    while (l<=r)
    {
        ss << l;
        vec.push_back(ss.str());
        l++;
        ss.str("");
    }
    set_list_project_name(vec);
}

void regex_change_file(string path_old, string path_new, string regex_old, string regex_new)
{
    ifstream in(path_old);
    ostringstream sstr;
    sstr << in.rdbuf();
    string data_old = sstr.str();
    in.close();

    string data_new = regex_replace(data_old, regex(regex_old), regex_new);

    ofstream out(path_new);
    out << data_new;
    out.close();
}

int main(int argc, char *argv[])
{
    string cb_version="20.03";

    ///改
    //string path_out_dir = "C:/Users/congm/OneDrive/code_competition/ABC349/";

    ///G813
    string path_out_dir = "C:/Users/chenguanbin/OneDrive/code_competition/ABC350/";

    ///改
    //string project_dir = "C:/Users/congm/OneDrive/code_competition/_auto_create_multiply_CodeBlocks_project";

    //G813
    string project_dir = "C:/Users/chenguanbin/OneDrive/code_competition/_auto_create_multiply_CodeBlocks_project";

    ///基本不用改
    string muban_name = "muban1";
    string muban_cpp = project_dir + "/" + muban_name + "/" + "main.cpp";

    string muban_cbp = project_dir + "/" + muban_name + "/" + muban_name + ".cbp";
    string muban_layout = project_dir + "/" + muban_name + "/" + muban_name + ".layout";

    string path_out_dir_2;
    char path_temp[300];
    int project_name_mode=2, l1=1,r1=3; ///project_name_mode=2 决定文件名是A-G还是1-7
    char l2='A',r2='G';
    bool add_test_project = 1;  //是否每个文件都加入test_xxx

    assert(argc == 1 || argc == 4);
    if (argc == 4)
    {
        path_out_dir = argv[1];
        path_out_dir = regex_replace(path_out_dir, regex("zzz"), "/");
        if ((argv[2][0] >= 'A' && argv[2][0] <= 'Z') || (argv[2][0] >= 'a' && argv[2][0] <= 'z'))
        {
            project_name_mode = 2;
            l2 = argv[2][0];
            r2 = argv[3][0];
        }
        else
        {
            project_name_mode = 1;
            l1 = atoi(argv[2]);
            r1 = atoi(argv[3]);
        }

        /*
        cout << "project_name_mode = " << path_out_dir << endl;
        cout << project_name_mode << endl;
        if (project_name_mode==1)
            cout << l1 << " " << r1 << endl;
        else if (project_name_mode==2)
            cout << l2 << " " << r2 << endl;
        */
        //exit(1);
    }

    //_getcwd(path_temp, 256); cout << path_temp << endl; exit(1);

    string muban_project_name = muban_cbp.substr(muban_cbp.rfind("/")+1, muban_cbp.length()-4-muban_cbp.rfind("/")-1);
    path_out_dir = path_out_dir + "/";
    _mkdir(path_out_dir.c_str());
    if (project_name_mode==1)
        set_vector_string(l1,r1);
    else if (project_name_mode==2)
        set_vector_string_character(l2,r2);

    cout<<"sereval names = ";
    for (auto temp:list_project_name)
        cout<<temp<<" ";
    cout<<endl;
    cout<<endl<<endl<<endl<<endl<<endl;

    if (add_test_project)
    {
        vector<string> list_project_name_temp(list_project_name);
        for (auto d : list_project_name_temp)
            list_project_name.push_back("test_" + d);
    }

    cout<<"output path = "<<path_out_dir<<endl;

    for (string project_name:list_project_name)
    {
        path_out_dir_2 = path_out_dir + project_name + "/";


        _mkdir(path_out_dir_2.c_str());
        _mkdir((path_out_dir_2 + "/obj").c_str());
        _mkdir((path_out_dir_2 + "/obj/Debug").c_str());
        _mkdir((path_out_dir_2 + "/bin").c_str());
        _mkdir((path_out_dir_2 + "/bin/Debug").c_str());

        system(regex_replace("copy "+ muban_cpp + " " + path_out_dir_2 + "/main.cpp", regex("/"), "\\").c_str());
        regex_change_file(muban_cbp, path_out_dir_2 + project_name + ".cbp" , muban_project_name, project_name);
        regex_change_file(muban_layout, path_out_dir_2 + project_name + ".layout", muban_project_name, project_name);

        //exit(1);

        ///这个运行得比较慢
        ///mingw32-g++.exe 还是 g++.exe，看情况
        if (cb_version=="16.04")
        {
            sprintf(path_temp,"mingw32-g++.exe -Wall -fexceptions -g -std=c++11  -c %s/%s/main.cpp -o %s/%s/obj/Debug/main.o",path_out_dir,project_name,path_out_dir,project_name);
            system(path_temp);

            sprintf(path_temp,"mingw32-g++.exe -o %s/%s/bin/Debug/%s.exe %s/%s/obj/Debug/main.o",path_out_dir,project_name,project_name,path_out_dir,project_name);
            system(path_temp);
        }
        else if (cb_version=="20.03")
        {
            sprintf(path_temp,"g++.exe -Wall -fexceptions -g -std=c++11  -c %s/main.cpp -o %s/obj/Debug/main.o", path_out_dir_2.c_str(), path_out_dir_2.c_str());
            cout << path_temp << endl;
            system(path_temp);

            sprintf(path_temp,"g++.exe -o %s/bin/Debug/%s.exe %s/obj/Debug/main.o", path_out_dir_2.c_str(), project_name.c_str(), path_out_dir_2.c_str());
            cout << path_temp << endl;
            system(path_temp);
        }
    }
    return 0;
}
