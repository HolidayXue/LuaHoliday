#ifndef __DELEGATE_H__
#define __DELEGATE_H__
 
#include <typeinfo>
#include <list>
 
namespace delegates
{
    // base class for classes that want to detach themselves from the multi delegates
    class IDelegateUnlink
    {
    public:
        virtual ~IDelegateUnlink() { }
 
        IDelegateUnlink() { m_baseDelegateUnlink = this; }
        bool compare(IDelegateUnlink * _unlink) const { return m_baseDelegateUnlink == _unlink->m_baseDelegateUnlink; }
 
    private:
        IDelegateUnlink * m_baseDelegateUnlink;
    };
 
    inline IDelegateUnlink * GetDelegateUnlink(void * _base) { return 0; }
    inline IDelegateUnlink * GetDelegateUnlink(IDelegateUnlink * _base) { return _base; }
}
 
// Generation Number of delegates to the various parameters
 
// no parameters
#define DELEGATE_SUFFIX       0
#define DELEGATE_TEMPLATE
#define DELEGATE_TEMPLATE_PARAMS
#define DELEGATE_TEMPLATE_ARGS
#define DELEGATE_T_TEMPLATE_PARAMS  <typename T>
#define DELEGATE_T_TEMPLATE_ARGS <T>
#define DELEGATE_PARAMS
#define DELEGATE_ARGS
#define DELEGATE_TYPENAME
 
#include "delegate_imp.h"
 
// one parameter
#define DELEGATE_SUFFIX       1
#define DELEGATE_TEMPLATE   template
#define DELEGATE_TEMPLATE_PARAMS  <typename TP1>
#define DELEGATE_TEMPLATE_ARGS    <TP1>
#define DELEGATE_T_TEMPLATE_PARAMS  <typename T, typename TP1>
#define DELEGATE_T_TEMPLATE_ARGS    <T, TP1>
#define DELEGATE_PARAMS       TP1 p1
#define DELEGATE_ARGS         p1
#define DELEGATE_TYPENAME     typename
 
#include "delegate_imp.h"
 
// two parameters
#define DELEGATE_SUFFIX       2
#define DELEGATE_TEMPLATE   template
#define DELEGATE_TEMPLATE_PARAMS  <typename TP1, typename TP2>
#define DELEGATE_TEMPLATE_ARGS    <TP1, TP2>
#define DELEGATE_T_TEMPLATE_PARAMS  <typename T, typename TP1, typename TP2>
#define DELEGATE_T_TEMPLATE_ARGS    <T, TP1, TP2>
#define DELEGATE_PARAMS       TP1 p1, TP2 p2
#define DELEGATE_ARGS         p1, p2
#define DELEGATE_TYPENAME     typename
 
#include "delegate_imp.h"
 
// three parameters
#define DELEGATE_SUFFIX       3
#define DELEGATE_TEMPLATE   template
#define DELEGATE_TEMPLATE_PARAMS  <typename TP1, typename TP2, typename TP3>
#define DELEGATE_TEMPLATE_ARGS    <TP1, TP2, TP3>
#define DELEGATE_T_TEMPLATE_PARAMS  <typename T, typename TP1, typename TP2, typename TP3>
#define DELEGATE_T_TEMPLATE_ARGS    <T, TP1, TP2, TP3>
#define DELEGATE_PARAMS       TP1 p1, TP2 p2, TP3 p3
#define DELEGATE_ARGS         p1, p2, p3
#define DELEGATE_TYPENAME     typename
 
#include "delegate_imp.h"
 
// four parameters
#define DELEGATE_SUFFIX       4
#define DELEGATE_TEMPLATE   template
#define DELEGATE_TEMPLATE_PARAMS  <typename TP1, typename TP2, typename TP3, typename TP4>
#define DELEGATE_TEMPLATE_ARGS    <TP1, TP2, TP3, TP4>
#define DELEGATE_T_TEMPLATE_PARAMS  <typename T, typename TP1, typename TP2, typename TP3, typename TP4>
#define DELEGATE_T_TEMPLATE_ARGS    <T, TP1, TP2, TP3, TP4>
#define DELEGATE_PARAMS       TP1 p1, TP2 p2, TP3 p3, TP4 p4
#define DELEGATE_ARGS         p1, p2, p3, p4
#define DELEGATE_TYPENAME     typename
 
#include "delegate_imp.h"
 
// five parameters
#define DELEGATE_SUFFIX       5
#define DELEGATE_TEMPLATE   template
#define DELEGATE_TEMPLATE_PARAMS  <typename TP1, typename TP2, typename TP3, typename TP4, typename TP5>
#define DELEGATE_TEMPLATE_ARGS    <TP1, TP2, TP3, TP4, TP5>
#define DELEGATE_T_TEMPLATE_PARAMS  <typename T, typename TP1, typename TP2, typename TP3, typename TP4, typename TP5>
#define DELEGATE_T_TEMPLATE_ARGS    <T, TP1, TP2, TP3, TP4, TP5>
#define DELEGATE_PARAMS       TP1 p1, TP2 p2, TP3 p3, TP4 p4, TP5 p5
#define DELEGATE_ARGS         p1, p2, p3, p4, p5
#define DELEGATE_TYPENAME     typename
 
#include "delegate_imp.h"

// six parameters
#define DELEGATE_SUFFIX       6
#define DELEGATE_TEMPLATE   template
#define DELEGATE_TEMPLATE_PARAMS  <typename TP1, typename TP2, typename TP3, typename TP4, typename TP5, typename TP6>
#define DELEGATE_TEMPLATE_ARGS    <TP1, TP2, TP3, TP4, TP5, TP6>
#define DELEGATE_T_TEMPLATE_PARAMS  <typename T, typename TP1, typename TP2, typename TP3, typename TP4, typename TP5, typename TP6>
#define DELEGATE_T_TEMPLATE_ARGS    <T, TP1, TP2, TP3, TP4, TP5, TP6>
#define DELEGATE_PARAMS       TP1 p1, TP2 p2, TP3 p3, TP4 p4, TP5 p5, TP6 p6
#define DELEGATE_ARGS         p1, p2, p3, p4, p5, p6
#define DELEGATE_TYPENAME     typename

#include "delegate_imp.h"
 
#endif // __DELEGATE_H__