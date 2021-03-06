#ifndef FACTORY_H
#define FACTORY_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Expression.h"

namespace GEP
{

void CreateRamdonExpression(Expression &expression,std::vector<Operator> &operators,int head,int tail,int nb_var,float c_max,float c_min);

Element             RamdonElement(std::vector<Operator> &operators,int nb_var,float c_max,float c_min,bool in_head=true);
Element::Type       RamdonType();
//Element::Operator   RamdonOperator();
float               RamdonConstante(float c_max,float c_min);
int                 RamdonVariable(int nb_var);

void                RefineConstante(float &current,float step);

PtrNode             CreateTreeFromExpression(std::vector<Element> expression);

} // namespace GEP
#endif // FACTORY_H
