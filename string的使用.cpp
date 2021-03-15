#include<iostream>
#include<cstring>
using namespace std;
void fun(char *str,int length){
  int k=0;
  while(*str++!='\0'&&*str==NULL){
    if(*str==' '){
      length+=2;
      str[length]='\0';
    }
  }
  for(int i=0;i<length;){
    for(int j=length;j!=i;){
      str[j--]=str[i++];
    }
  }
}
int main(){
  char *str="we new file";
  fun(str,strlen(str));
  printf("%s",str);
  return 0;
}
