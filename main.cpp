#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
    
int main()
{
    string g="aAeEiIoOuUyY";
    string s="bcdfghjklmnpqrstvwxz";
    string newstr;
    vector<string> vctr, vctrs, vctrg;
    ifstream file;
    int soglas, glas;
    file.open("text.txt");
 
    string word;
    while (file >> word) {
        // Сохраняем каждое слово в вектор
        vctr.push_back(word);
    }
    file.close();
 
    for (long unsigned int i = 0; i < vctr.size(); ++i) {
        //Считаем сколько согласных в слове
        soglas = 0;
        for(int j=0; j<vctr[i].size(); ++j) {
            for(int h=0; h<s.size(); ++h) {
                    if(vctr[i][j]==s[h])soglas++;
            }
        }
        //Сохраняем слова содержащий не более трех согласных в отдельный вектор
        if (soglas < 4) {
            vctrs.push_back(vctr[i]);
 
        }
        //В остальных словах убираем гласные и дублируем согласные и также сохраняем в отдельный вектор
        else {
            newstr ="";
            for(int j=0; j<vctr[i].size(); ++j) {
                glas = 0;
                for(int h=0; h<g.size(); ++h) {
                    if(vctr[i][j]==g[h])glas++;
                }
                if (glas == 0) {
                    newstr = newstr + vctr[i][j];
                    newstr = newstr + vctr[i][j];
                }
            }
 
            vctrg.push_back(newstr);
        }
    }
 
    sort(begin(vctrs), end(vctrs));
 
    // Выводим отсортированный список слов содержащий не более трех согласных
    for (long unsigned int i = 0; i < vctrs.size(); ++i) {
        cout << vctrs[i] << " ";
    }
    // Выводим остальные слова у которых удалили гласные и продублировали согласные
    for (long unsigned int i = 0; i < vctrg.size(); ++i) {
        cout << vctrg[i] << " ";
    }
    cout << endl;
  
}
