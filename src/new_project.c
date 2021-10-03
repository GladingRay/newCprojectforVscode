#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../include/my_string.h"

void generate_dir(char * root_dir){
    char bscmd_mkdir[] = "mkdir -p ";
    char * ss2[] = {root_dir, "/include"};
    char * path_include = my_strcat(ss2,2);
    ss2[1] = "/.vscode";
    char * path_vscode = my_strcat(ss2, 2);
    ss2[1] = "/src";
    char * path_src = my_strcat(ss2, 2);
    char * path_s[] = {path_include, path_src, path_vscode};
    char * command = NULL;
    for(int i=0;i<3;i++){
        ss2[0] = bscmd_mkdir;
        ss2[1] = path_s[i];
        command = my_strcat(ss2, 2);
        system(command);
        free(command);
        free(path_s[i]);
    }
}

void generate_tasks(char * root_dir, char * target){
    char * ss3[] = {root_dir, "/.vscode/", "tasks.json"};
    char * file_task = my_strcat(ss3, 3);
    ss3[0] = "				\"${workspaceFolder}/";
    ss3[1] = target;
    ss3[2] = "\",\n";
    char * lines_12 = my_strcat(ss3, 3);
    char * tasks_lines[27] = {
        "{\n",
        "	\"version\": \"2.0.0\",\n",
        "	\"tasks\": [\n",
        "		{\n",
        "			\"type\": \"cppbuild\",\n",
        "			\"label\": \"C/C++: g++ 生成活动文件\",\n",
        "			\"command\": \"/usr/bin/g++\",\n",
        "			\"args\": [\n",
        "				\"-g\",\n",
        "				\"${workspaceFolder}/src/*.cpp\",\n",
        "				\"-o\",\n",
        lines_12,
        "			],\n",
        "			\"options\": {\n",
        "				\"cwd\": \"${workspaceFolder}\"\n",
        "			},\n",
        "			\"problemMatcher\": [\n",
        "				\"$gcc\"\n",
        "			],\n",
        "			\"group\": {\n",
        "				\"kind\": \"build\",\n",
        "				\"isDefault\": true\n",
        "			},\n",
        "			\"detail\": \"编译器: /usr/bin/g++\"\n",
        "		}\n",
        "	]\n",
        "}\n"
    };
    FILE * pfile = NULL;
    pfile = fopen(file_task, "w");
    for(int i=0;i<27;i++){
        fputs(tasks_lines[i],pfile);
    }
    fclose(pfile);
    free(file_task);
    free(lines_12);
}

void generate_launch(char * root_dir, char * target){
    char * ss3[] = {root_dir, "/.vscode/", "launch.json"};
    char * file_launch = my_strcat(ss3, 3);
    ss3[0] = "            \"program\": \"${workspaceFolder}/";
    ss3[1] = target;
    ss3[2] = "\",\n";
    char * lines_8 = my_strcat(ss3, 3);
    char * launch_lines[25] = {
        "{\n",
        "    \"version\": \"0.2.0\",\n",
        "    \"configurations\": [\n",
        "        {\n",
        "            \"name\": \"g++ - 生成和调试活动文件\",\n",
        "            \"type\": \"cppdbg\",\n",
        "            \"request\": \"launch\",\n",
        lines_8,
        "            \"args\": [],\n",
        "            \"stopAtEntry\": false,\n",
        "            \"cwd\": \"${workspaceFolder}\",\n",
        "            \"environment\": [],\n",
        "            \"MIMode\": \"gdb\",\n",
        "            \"setupCommands\": [\n",
        "                {\n",
        "                    \"description\": \"为 gdb 启用整齐打印\",\n",
        "                    \"text\": \"-enable-pretty-printing\",\n",
        "                    \"ignoreFailures\": true\n",
        "                }\n",
        "            ],\n",
        "            \"preLaunchTask\": \"C/C++: g++ 生成活动文件\",\n",
        "            \"miDebuggerPath\": \"/usr/bin/gdb\"\n",
        "        }\n",
        "    ]\n",
        "}\n"
    };
    FILE * pfile = NULL;
    pfile = fopen(file_launch, "w");
    for(int i=0;i<25;i++){
        fputs(launch_lines[i], pfile);
    }
    fclose(pfile);
    free(lines_8);
    free(file_launch);
}

void generate_c_example(char * root_dir){
    char * ss4[] = {root_dir, "/src/", root_dir, ".cpp"};
    char * file_c_example = my_strcat(ss4, 4);
    char * c_lines[6] = {
        "#include<stdio.h>\n",
        "\n",
        "int main(int argc, char * argv[]){\n",
        "    printf(\"wdnmd\\n\");\n",
        "    return 0;\n",
        "}"
    };
    FILE * pfile = NULL;
    pfile = fopen(file_c_example, "w");
    for(int i=0;i<6;i++){
        fputs(c_lines[i], pfile);
    }
    fclose(pfile);
    free(file_c_example);
}

int main(int argc, char * argv[]){
    if(argc!=3){
        printf("number of argv is not correct!\n");
        return 0;
    }
    generate_dir(argv[1]);   
    generate_tasks(argv[1], argv[2]);
    generate_launch(argv[1], argv[2]);
    generate_c_example(argv[1]);
    printf("[%s] struct successfully, please check all files generated.\n", argv[1]);
    return 0;
}
