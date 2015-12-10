/**
	����40�ڸ�unsigned int��������û�Ź���ģ�
	Ȼ���ٸ�һ��������ο����ж�������Ƿ�����40�ڸ�������
**/
#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
const unsigned SIZE = 512000000;//512�׾�̬�洢���ɴ���40.96������

class Bitmap {
    typedef struct Byte {
        unsigned char bit8;
		static const unsigned char mask[9];//����ȡ��һ���ֽ�ÿһλ�ĸ�������
        Byte()
        {
            bit8 = 0;
        }
        //���ø�λ�����Ǵ洢����
        void set1(unsigned at)
        {
            bit8 |= mask[at];
        }
        //��ȡ��λ�Ƿ�����
        bool get1(unsigned at)
        {
            return bit8 & mask[at];
        }
    } Byte;
    Byte *m_byte;
    unsigned m_size;
public:
    Bitmap(unsigned _size)
    {
        m_byte = new Byte[(_size+7)/8];
        m_size = _size;
    }
    virtual ~Bitmap()
    {
        delete[] m_byte;
        m_size = 0;
    }
    //�洢һ������
    bool push(unsigned data)
    {
        if(data>=m_size)
            return false;
        m_byte[data/8].set1(data%8);
        return true;
    }
    //��ȡһ�������Ƿ����
    bool find(unsigned data)
    {
        return data>=m_size ? 0 : m_byte[data/8].get1(data%8);
    }
    //�����ܴ洢�����ݸ���
    unsigned size()
    {
        return m_size;
    }
    //���������ʵ�ֳ��ù���
    //�洢һ������
    bool operator>>(unsigned data)
    {
        return push(data);
    }
    //��ȡһ�������Ƿ����
    bool operator<<(unsigned data)
    {
        return find(data);
    }
    //���ʵ�ĳ�����ݿ�
    Byte& operator[](unsigned i)
    {
        if(i>=m_size/8)
            throw "index out of range";
        return m_byte[i];
    }
};
const unsigned char Bitmap::Byte::mask[9] = {0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1};//����ȡ��һ���ֽ�ÿһλ�ĸ�������

int main()
{
    Bitmap bitmap(8*SIZE);//���Դ洢40+������
    ifstream file("in.txt");
    unsigned read, i=0, t1 = clock();
    for(i=0; i<SIZE; ++i)
        if(file>>read)
            bitmap>>read;
        else
            break;
    file.close();
    cout<<"���洢"<<i/10000<<"W ����, "<<"��ʱ: "<<clock()-t1<<"ms"<<endl;
    t1 = clock();
    for(i=0; i<1000000; ++i)
        if(bitmap<<i)
            ;
    cout<<"����"<<i/10000<<"W ���ݹ���ʱ: "<<clock()-t1<<"ms"<<endl;
    cout<<"��������Ҫ����������:"<<endl;
    while(cin>>read) {
        if(bitmap<<read)
            cout<<"�Ѵ洢"<<read<<endl;
        else
            cout<<"Error: δ�洢"<<read<<endl;
    }
    return 0;
}
