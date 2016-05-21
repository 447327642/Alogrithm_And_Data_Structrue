#pragma once
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <cstring>
using namespace std ;

template< typename Value_t >
class TireMap {
public:
    typedef pair< string , Value_t > Kv_t ;
    struct Node {
        Kv_t * pKv ;
        Node* Children[256] ;
        Node() {
            pKv = 0;
            memset( Children , 0 , sizeof( Children ) ) ;
        }
        ~Node( ) {
            delete pKv ;
        }
    };

    TireMap();
    virtual ~TireMap() ;
    //����[]  ��������� map , unorder_map �����ӿ�һ����
    Value_t& operator[]( const string& strKey ) ;
    // ������������
    void clear() ;
    const list< Kv_t >& GetKeyValueList() const {
        return m_Kvs ;
    }

protected:
    // ɾ��һ����
    static void DeleteTree( Node *pNode ) ;
protected:
    // �����ڵ�
    Node * m_pRoot ;
    // ӳ��ļ�ֵ�б�
    list< Kv_t > m_Kvs ;
};

template< typename Value_t >
TireMap<Value_t>::TireMap() {
    m_pRoot = new Node() ;
}

template< typename Value_t >
TireMap<Value_t>::~TireMap() {
    //clear( ) ;
    //delete m_pRoot ;
}

template< typename Value_t >
void TireMap<Value_t>::clear() {
    for ( int i = 0 ; i < 256 ; ++i ) {
        if ( m_pRoot->Children[ i ] != 0 ) {
            DeleteTree( m_pRoot->Children[ i ] ) ;
            m_pRoot->Children[ i ] = 0 ;
        }
    }
    m_Kvs.clear( ) ;
}

template< typename Value_t >
void TireMap<Value_t>::DeleteTree( Node * pRoot ) {
    // BFS ɾ����
    stack< Node* > stk ;
    stk.push( pRoot ) ;
    for ( ; stk.size( ) > 0 ; ) {
        Node * p = stk.top() ;
        stk.pop( ) ;
        // ��չ
        for ( int i = 0 ; i < 256 ; ++i ) {
            Node* p2 = p->Children[ i ] ;
            if ( p2 == 0 )
                continue;
            stk.push( p2 ) ;
        }
        delete p ;
    }
}

template< typename Value_t >
Value_t& TireMap<Value_t>::operator[]( const string& strKey ) {
    Node * pNode = m_pRoot ;
    // �������߲�����·��
    for ( size_t i = 0 , size = strKey.size( ) ; i < size ; ++i ) {
        const char& ch = strKey[ i ] ;
        Node*& Child = pNode->Children[ ch ] ;
        if ( Child == 0 )
            pNode = Child = new Node() ;
        else
            pNode = Child ;
    }
    // ���û�������ֶεĻ���������һ����
    if ( pNode->pKv == 0 ) {
        m_Kvs.push_back( Kv_t( strKey , Value_t() ) ) ;
        pNode->pKv = &*( --m_Kvs.end( ) ) ;
    }
    return pNode->pKv->second ;
}

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <iostream>
//#include "TireMap.h"
using namespace std ;

#define FOR(it,var) for(auto it = var.begin();it!=var.end();++it)
// ������� Count ������ַ���ϵġ����ʡ�
template< typename StringList_t >
int CreateStirngs( StringList_t& strings , int Count ) {
    int nTimeStart , nElapsed ;
    nTimeStart = clock( ) ;
    strings.clear( ) ;
    for ( int i = 0 ; i < Count ; ++i ) {
        int stringLen = 5 ;
        string str ;
        for ( int j = 0 ; j < stringLen ; ++j ) {
            char ch = 'a' + rand( ) % ( 'z' - 'a' + 1 ) ;
            str.push_back( ch ) ;
        }
        strings.push_back( str ) ;
    }
        strings.push_back( "abcde" ) ;

    nElapsed = clock( ) - nTimeStart ;
    return nElapsed ;
}

// ���� Count ���������ݡ�ͬ��������Щ���Ͷ�Ӧ���ַ���
template< typename StringList_t , typename IntList_t >
int CreateNumbers( StringList_t& strings , IntList_t& Ints , int Count ) {
    strings.clear( ) ;
    Ints.clear( ) ;

    for ( int i = 0 ; i < Count ; ++i ) {
        int n =rand( ) % 0x00FFFFFF ;
        char sz[ 256 ] = { 0 } ;
        sprintf(sz,"%d",n);

        strings.push_back( sz ) ;
        Ints.push_back( n ) ;
    }

    return 0 ;
}

// Tire ��ȷ�Լ��
string Check( const unordered_map< string , int >& Right , const TireMap< int >& Tire ) {
    string strInfo = "Tire ͳ����ȷ" ;

    const auto& TireRet = Tire.GetKeyValueList( ) ;
    unordered_map< string , int > ttt ;
    //for ( auto kv = TireRet.front();kv!=TireRet.end();++kv )
    FOR(kv,TireRet) {
        ttt[ kv->first ] = kv->second ;
    }

    if ( ttt.size( ) != Right.size( ) ) {
        strInfo = "Tireͳ���д�" ;
    } else {
        FOR (kv, ttt) {
            auto it = Right.find( kv->first )  ;
            if ( it == Right.end( ) ) {
                strInfo = "Tireͳ���д�" ;
                break ;
            } else if ( kv->second != it->second ) {
                strInfo = "Tireͳ���д�" ;
                break ;
            }
        }
    }

    return strInfo ;

}

// ͳ��ģ�庯����������map , unordered_map , TrieMap ��ͳ��
template< typename StringList_t , typename Counter_t >
int Count( const StringList_t& strings , Counter_t& Counter ) {
    int nTimeStart = clock() ;
    FOR (str,strings) {
        ++Counter[*str];
    }
    return clock( ) - nTimeStart;
}

int main( int argc , char* argv[ ] ) {
    map< string , int > ElapsedInfo ;
    int nTimeStart , nElapsed ;

    // ����50000���������
    list< string > strings ;
    nElapsed = CreateStirngs( strings , 500000 ) ;
    //ElapsedInfo[ "���ɵ��� ��ʱ" ] = nElapsed  ;

    // �� map ��ͳ��
    map< string , int > Counter1 ;
    nElapsed = Count( strings , Counter1 ) ;
    ElapsedInfo[ "ͳ�Ƶ��� ��map ��ʱ" ] = nElapsed  ;

    // �� unordered_map ��ͳ��
    unordered_map< string , int > Counter2 ;
    nElapsed = Count( strings , Counter2 ) ;
    ElapsedInfo[ "ͳ�Ƶ��� ��unordered_map ��ʱ" ] =  nElapsed  ;

    // �� Tire ��ͳ��
    TireMap< int > Counter3 ;
    nElapsed = Count( strings , Counter3 ) ;
    ElapsedInfo[ "ͳ�Ƶ��� ��Tire ��ʱ" ] = nElapsed  ;
    cout<<Counter3["abcde"]<<endl;

    // Tire ͳ�ƵĽ������ȷ�Լ��
    string CheckRet = Check( Counter2 , Counter3 ) ;

    // �ù�ϣ��ͳ���������ֳ��ֵĴ���
    // �� ��Tireͳ��ͬ�����������ֳ��ֵĴ����� �Ա�
    // ��Ȼ����Tireͳ�ƵĻ�����Ҫ������������ת���ɶ�Ӧ���ַ����ı�ʾ��

    list< int > Ints ;
    CreateNumbers( strings , Ints , 500000 ) ;
    unordered_map< int , int > kivi ;
    nTimeStart = clock();
    FOR(num , Ints ) {
        ++kivi[ *num ] ;
    }
    nElapsed = clock( ) - nTimeStart ;
    ElapsedInfo[ "ͳ������ unordered_map ��ʱ" ] = nElapsed  ;

    //Counter3.clear( ) ; ��仰�ǳ���ʱ����ΪҪ���������delete���ڵ㡣���п��ܻ�ǳ���������ע�͵�
    nElapsed = Count( strings , Counter3 ) ;
    ElapsedInfo[ "ͳ������ ��Tire ��ʱ" ] = nElapsed  ;

    FOR(it,ElapsedInfo) {
        cout<<it->first<<" : "<<it->second<<endl;
    }

    return 0;
}
