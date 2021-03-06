////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Population.h"
#include "Factory.h"
#include <algorithm>


namespace GEP
{
////////////////////////////////////////////////////////////
Population::Population(Setting &_setting):
    expressions(_setting.NbTree),setting(_setting)
{
    nb_parent = expressions.size()-(expressions.size()*setting.PorCentDead/100);
    head = setting.HeaderSize;
    unsigned int NbMaxArgument = 2;
    tail = head*(NbMaxArgument-1)+1;
    size_tree = tail+head;
}

////////////////////////////////////////////////////////////
Population::~Population()
{
    //dtor
}

////////////////////////////////////////////////////////////
void Population::FirstGeneration()
{
    for(auto &expression:expressions)
        CreateRamdonExpression(expression,setting.operators,head,tail,setting.NbVariable,setting.Cmax,setting.Cmin);
}

////////////////////////////////////////////////////////////
void Population::NextGeneration()
{
    //If pouplation is not sort
    if(!sort)
        Sort();
    //This new population is not sorted, because children may be better
    sort=false;
    //Make the next generation
    for(unsigned int i = nb_parent; i<expressions.size(); i++)
    {
        Expression &child   = expressions[i];
        unsigned int mother = RamdonVariable(nb_parent);
        unsigned int father = RamdonVariable(nb_parent);
        if(mother == father)
            continue;
        Crossing(child,expressions[mother],expressions[father]);
        Mutation(child);
        child.Initialize();
    }
}

////////////////////////////////////////////////////////////
void Population::ImproveConstante()
{
    //If pouplation is not sort
    if(!sort)
        Sort();
    //This new population can be not sorted, because children can be better
    sort=false;
    //Child have same form its parent
    for(unsigned int i = nb_parent; i<expressions.size(); i++)
    {
        Expression &child   = expressions[i];
        unsigned int parent = RamdonVariable(nb_parent);
        child.expression = expressions[parent].expression;
        for(auto &ele:child.expression)
        {
            if(ele.type==Element::CONSTANTE)
                RefineConstante(ele.value.constante,setting.Cstep);
        }
        child.Initialize();
    }
}

////////////////////////////////////////////////////////////
void Population::Crossing(Expression &child,const Expression &mother,const Expression &father)
{
    unsigned int cross = RamdonVariable(size_tree);
    child.Clear();
    for(unsigned int i=0; i<cross; i++)
        child.Add(mother.expression[i]);
    for(unsigned int i=cross; i<size_tree; i++)
        child.Add(father.expression[i]);
}

////////////////////////////////////////////////////////////
void Population::Mutation(Expression &child)
{
    for(unsigned int i=0; i<child.expression.size(); i++)
        if(RamdonVariable(100)<setting.ProbaMutation)
        {
            bool in_head = (i<head);
            child.expression[i] = RamdonElement(setting.operators,setting.NbVariable,setting.Cmax,setting.Cmin,in_head);
        }
}

////////////////////////////////////////////////////////////
void Population::Sort()
{
    std::sort(expressions.begin(),expressions.end());
    sort=true;
}

} // namespace GEP
