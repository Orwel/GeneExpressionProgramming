#ifndef DISPLAY_H
#define DISPLAY_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Expression.h"
#include "Result.h"
#include <string>

namespace GEP
{


/////////////////////////////////////////////////
/// \brief Display a expression in GEP form
///
/// \param expression it is display in cout
///
/////////////////////////////////////////////////
void DisplayExpression(Expression &expression);

std::string ExpressionToString(Expression &expression);

/////////////////////////////////////////////////
/// \brief Return string same expression in math form
///
/// \param expression will be tranformed in string
/// \return math form of expresion
///
/////////////////////////////////////////////////
std::string ExpressionMathToString(Expression &expression);

/////////////////////////////////////////////////
/// \brief Display a expression with math form
///
/// \param expression it is display in cout
///
/////////////////////////////////////////////////
void DisplayExpressionMath(Expression &expression);

/////////////////////////////////////////////////
/// \brief Translate element to string
///
/// \param element it is translate to string
/// \return string who correspond at element
///
/////////////////////////////////////////////////
std::string ElementToString(Element &element);

} // namespace GEP

#endif // DISPLAY_H
