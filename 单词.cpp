#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Word{
    string eng;
    string chn;
};

vector<Word> dict;

void initDict(){
    Word temp;
    temp.eng = "apple"; temp.chn = "苹果";
    dict.push_back(temp);
    temp.eng = "banana"; temp.chn = "香蕉";
    dict.push_back(temp);
    temp.eng = "book"; temp.chn = "书籍，书本";
    dict.push_back(temp);
    temp.eng = "computer"; temp.chn = "电脑，计算机";
    dict.push_back(temp);
    temp.eng = "hello"; temp.chn = "你好";
    dict.push_back(temp);
    temp.eng = "world"; temp.chn = "世界";
    dict.push_back(temp);
    temp.eng = "student"; temp.chn = "学生";
    dict.push_back(temp);
    temp.eng = "teacher"; temp.chn = "老师，教师";
    dict.push_back(temp);
    temp.eng = "program"; temp.chn = "程序，节目";
    dict.push_back(temp);
    temp.eng = "code"; temp.chn = "代码，编码";
    dict.push_back(temp);
}

void exactSearch(const string& target){
    bool f = false;
    vector<Word>::iterator it;
    for(it = dict.begin(); it != dict.end(); it++){
        if(it->eng == target){
            cout<<"\n【查询结果】\n"<<left<<setw(15)<<"英文单词"<<"释义\n-------------------------\n"<<left<<setw(15)<<it->eng<<it->chn<<endl;
            f = true;
            break;
        }
    }
    if(!f)
        cout<<"未找到该单词！\n";
}

void fuzzySearch(const string& target){
    vector<Word> r;
    vector<Word>::iterator it;
    for(it = dict.begin(); it != dict.end(); it++){
        if(it->eng.find(target) != string::npos)
            r.push_back(*it);
    }
    if(r.empty()){
        cout<<"无匹配单词！\n";
        return;
    }
    cout<<"\n【模糊匹配结果】共"<<r.size()<<"个\n"<<left<<setw(15)<<"英文单词"<<"释义\n-------------------------\n";
    vector<Word>::iterator rit;
    for(rit = r.begin(); rit != r.end(); rit++)
        cout<<left<<setw(15)<<rit->eng<<rit->chn<<endl;
}

void addWord(){
    string e,c;
    Word temp;
    cout<<"请输入英文单词：";
    cin>>e;
    cin.ignore();
    getline(cin,c);
    temp.eng = e;
    temp.chn = c;
    dict.push_back(temp);
    cout<<"单词添加成功！\n";
}

void showAll(){
    if(dict.empty()){
        cout<<"词典为空！\n";
        return;
    }
    cout<<"\n【全部词汇列表】共"<<dict.size()<<"个\n"<<left<<setw(15)<<"英文单词"<<"释义\n-------------------------\n";
    vector<Word>::iterator it;
    for(it = dict.begin(); it != dict.end(); it++)
        cout<<left<<setw(15)<<it->eng<<it->chn<<endl;
}

void printMenu(){
    cout<<"\n===== C++ 单词查询工具 =====\n1. 精确查词\n2. 模糊搜索\n3. 添加新单词\n4. 查看全部单词\n0. 退出程序\n请输入功能序号：";
}

int main(){
    initDict();
    int op;
    string word;
    while(1){
        printMenu();
        cin>>op;
        switch(op){
            case 1:
                cout<<"输入要精确查询的单词：";
                cin>>word;
                exactSearch(word);
                break;
            case 2:
                cout<<"输入模糊匹配关键词：";
                cin>>word;
                fuzzySearch(word);
                break;
            case 3:
                addWord();
                break;
            case 4:
                showAll();
                break;
            case 0:
                cout<<"程序已退出，再见！\n";
                return 0;
            default:
                cout<<"输入错误，请选择0-4！\n";
        }
    }
    return 0;
}
