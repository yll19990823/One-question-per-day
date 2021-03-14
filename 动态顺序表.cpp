#include<iostream>
#include<cstdlib>
using namespace std;

typedef int DateType;
typedef struct SepList{
  DateType* array;
  size_t size;//size_t:�޷������ͣ������� size:Ԫ�ظ���
  size_t capacity;//capacity:����,����ǰ���ÿռ�
}SepList;

//˳����ʼ��
void SepListInit(SepList* s){
  s->array=(DateType*)malloc(sizeof(DateType)*4);
  s->size=0;
  s->capacity=4;
}
//���˳��������Ƿ���㣬��������
void checkCapacity(SepList* s){
  //����˳�������
  if(s->size==s->capacity){
    s->capacity*=2;
    /*
		//���ռ�
		DateType* newArray = (DateType*)malloc(sizeof(DateType) * s1->capacity);
		//����
		memcpy(newArray, s->array, s->size * sizeof(DateType);
		//�ͷſռ�
		free(s->array);
		s->array = newArray;
		*/
    s->array=(DateType*)realloc(s->array,sizeof(DateType)*s->capacity);
  }
}
//˳�������
void SepListDestory(SepList* s){
  free(s->array);
  s->size=0;
  s->capacity=10;
}
//˳�������Ԫ�ش�ӡ
void SepListPrint(SepList* s){
  for(int i=0;i<s->size;i++){
    cout << s->array[i] << " ";
  }
  cout << endl;
}
//˳���β��
void SepListPushBack(SepList* s,DateType date){
  checkCapacity(s);
  s->array[s->size++]=date;
}
//˳���βɾ
void SepListPopBack(SepList* s){
  if(s->size) s->size--;
}
//˳���ͷ��
void SepListPushFront(SepList* s,DateType date){
  checkCapacity(s);
  for(int i=s->size++;i>0;i--){
    s->array[i]=s->array[i-1];
  }
  s->array[0]=date;
}
//˳���ͷɾ
void SepListPopFront(SepList* s){
  if(s->size){
    for(int i=0;i<s->size-1;i++){
        s->array[i]=s->array[i+1];
    }
    s->size--;
  }
}
//˳����������Ԫ��λ��
int SepListFind(SepList* s,DateType date){
  for(int i=0;i<s->size;i++){
    if(s->array[i]==date) return i+1;
  }
  return -1;
}
//��˳���posλ�ô�����ĳһ����Ԫ��
void SepListInsert(SepList* s,size_t pos,DateType date){
  if(pos<=s->size){
    checkCapacity(s);
    for(int i=s->size++;i>pos;i--){
      s->array[i]=s->array[i-1];
    }
    s->array[pos]=date;
  }
}
//��˳���posλ�ô�ɾ��ĳһ����Ԫ��
void SepListErase(SepList* s,size_t pos){
  if(pos<s->size){
    for(int i=pos;i<s->size-1;i++){
        s->array[i]=s->array[i+1];
    }
    s->size--;
  }
}
int main(){
  SepList s;
  SepListInit(&s);
  int date;
  cin >> date;
  SepListPushBack(&s,date);
  //SepListPopBack(&s);
  cin >> date;
  SepListPushFront(&s,date);
  //SepListPopFront(&s);
  SepListPrint(&s);
  SepListInsert(&s,1,9);
  //SepListErase(&s,1);
  SepListPrint(&s);
  cout << "���ҵڶ�������dateֵ��˳����е�λ�ã�" << SepListFind(&s,date) << endl;
  SepListDestory(&s);
  return 0;
  return 0;
}
