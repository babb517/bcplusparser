#pragma once

#include <ostream>
#include <string>
#include <sstream>

#include "babb/utils/memory.h"

#include "bcplus/DomainType.h"
#include "bcplus/Location.h"


namespace bcplus {
namespace elements {

/// Base class for a parser element
class Element : public babb::utils::Referenced
{

public:
	/****************************************************************************/
	/* Public Types */
	/****************************************************************************/

	/// Container of enumeration of possible types
	struct Type {
		enum type {
			STATEMENT,
			FORMULA,
			TERM,
			MACRO
		};
	};




private:
	/****************************************************************************/
	/* Private Members */
	/****************************************************************************/

	/// Whether the element is surrounded by parentheses
	bool _parens;

	/// The type of element we're looking at
	Type::type _type;

	/// The start/end of this element in the original file
	Location _begin;
	Location _end;


public:
	/****************************************************************************/
	/* Constructor / Destructor */
	/****************************************************************************/
	/// Full constructor
	/// @param type The type of element this is
	/// @param begin The beginning location of this element
	/// @param end The ending location of this element
	/// @param parens Whether the element is surrounded by parentheses
	Element(Type::type type, Location const& begin = Location(NULL, 0, 0), Location const& end = Location(NULL, 0, 0), bool parens = false);

	/// Destructor stub
	virtual ~Element();

	/****************************************************************************/
	/* Public Methods */
	/****************************************************************************/
	
	/// Getter/setter for whether or not this element has parentheses
	inline bool parens() const							{ return _parens; }
	inline void parens(bool p)							{ _parens = p; }

	/// Determines the type of the element
	inline Type::type type() const						{ return _type; }

	/// Get/set the starting location of this element
	inline Location const& beginLoc() const				{ return _begin; }
    inline void beginLoc(Location const& loc)           { _begin = loc; }

	/// Get the ending location of this element
	inline Location const& endLoc() const				{ return _end; }
    inline void endLoc(Location const& loc)             { _end = loc; }

	/// Helper function to output a string representing this element.
	inline std::string str() const						{ std::stringstream out; output(out); return out.str(); }

	/// Does a deep copy of the element
	virtual Element* copy() const = 0;

	/// Outputs the element to the given stream
	/// @param out The output stream to write to
	virtual void output(std::ostream& out) const = 0;
	
	/// Get a description of the domain this element ranges over.
	virtual DomainType::type domainType() const = 0;
};

}}

/// Element output operator
inline std::ostream& operator<<(std::ostream& out, bcplus::elements::Element const& elem) {
	elem.output(out); return out;
}


