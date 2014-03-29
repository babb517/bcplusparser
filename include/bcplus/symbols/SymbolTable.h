#pragma once

#include <string>
#include <map>
#include <ostream>

#include <boost/filesystem/path.hpp>
#include <boost/iterator/transform_iterator.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/type_traits/remove_const.hpp>

#include "babb/utils/memory.h"

#include "bcplus/Configuration.h"
#include "bcplus/symbols/Symbol.h"
#include "bcplus/symbols/Resolver.h"

namespace bcplus  {
namespace symbols {

/// The bcplus's symbol table
class SymbolTable : public Resolver, public babb::utils::Referenced {
public:

	/// Simple functor to get the second element in a pair.
	struct get_second {
		/// this defines the return type of this functor
		template<typename> struct result;
		template < typename F, typename T >
		struct result<F(T)> {
			typedef typename boost::remove_reference<T>::type::second_type type;
		};

		template <typename K, typename V>
		V& operator() ( std::pair<K,V>& pr ) {
			return pr.second;
		}

		template <typename K, typename V>
		V const& operator() ( std::pair<K,V> const& pr ) const {
			return pr.second;
		}
	};



	/*******************************************************************************/
	/* Public Types */
	/*******************************************************************************/
	typedef std::map<std::string,babb::utils::ref_ptr<Symbol> > SymbolMap;
	typedef std::map<Symbol::Type::type, SymbolMap> TypeMap;

	typedef boost::transform_iterator<get_second, SymbolMap::iterator> iterator;
	typedef boost::transform_iterator<get_second, SymbolMap::const_iterator> const_iterator;

	typedef std::map<std::string, babb::utils::ref_ptr<const ReferencedString> > DataMap;

private:
	/*******************************************************************************/
	/* Private Members */
	/*******************************************************************************/

	/// Master symbol table mapping.
	TypeMap _symbols;

	/// The system configuration information
	babb::utils::ref_ptr<const Configuration> _config;

	/// Whether the symbol table has been successfully loaded.
	bool _good;

	/// A convenient place to store metadata
	DataMap _metadata;

public:

	/*******************************************************************************/
	/* Constructors / Destructor */
	/*******************************************************************************/
	/// Creates a symbol table based on the provided configuration information.
	/// @param config The system-wide configuration information to read from.
	SymbolTable(Configuration const* config);

	/// Destructor for the symbol table. 
	/// Saves the table state according to the configuration information.
	virtual ~SymbolTable();
	
	/*******************************************************************************/
	/* Public Functions */
	/*******************************************************************************/


	/// Iterate over the list of symbols matching the provided type
	inline iterator begin(Symbol::Type::type type) 							{ return iterator(_symbols[type].begin()); }
	inline const_iterator begin(Symbol::Type::type type) const				{ return const_iterator(_symbols.find(type)->second.begin()); }

	inline iterator end(Symbol::Type::type type)							{ return iterator(_symbols[type].end()); }
	inline const_iterator end(Symbol::Type::type type) const				{ return const_iterator(_symbols.find(type)->second.end()); }
	
	/// Determines if the symbol table was successfully loaded
	inline bool good() const												{ return _good; }

	/// Get the metadata for the given key, or NULL.
	ReferencedString const* getData(std::string const& key) const;
	
	/// Set the metadata for the given key.
	/// @param key The key for the data
	/// @param data The new data for the key
	/// @param override Whether to override existing data
	/// @return True if successful, false if the data exists and we didn't override it.
	bool setData(std::string const& key, ReferencedString const* data, bool override = false);
	


	// Inherited from Resolver
	virtual Symbol const* resolve(size_t typemask, std::string const& name, size_t arity = 0) const;
	virtual Symbol* resolve(size_t typemask, std::string const& name, size_t arity = 0);
	virtual bool create(Symbol* symbol);
	virtual Symbol* resolveOrCreate(Symbol* symbol);

private:
	/*******************************************************************************/
	/* Private Functions */
	/*******************************************************************************/

	/// internal resolve call to control tracing
	/// @param typemask A mask of the types to resolve
	/// @param name The base of the identifier to resolve
	/// @param arity The arity of the identifier to resolve
	/// @param trace Whether we should output trace information to the appropriate ostream.
	Symbol * _resolve(size_t typemask, std::string const& name, size_t arity = 0, bool trace = true);
	Symbol const* _resolve(size_t typemask, std::string const& name, size_t arity = 0, bool trace = true) const;


	/// Attempts to load the symbol table from the provided file
	/// @param path The file to load from.
	/// @return True if successful, false otherwise.
	bool load(boost::filesystem::path const& path);

	/// Attempts to save the symbol table to the provided file.
	/// @param path The file to save to.
	/// @return True if successful, false otherwise.
	bool save(boost::filesystem::path const& path) const;

	/// Attempts to load the macro definitions present within the configuration
	/// @param config The configuration to load the definitions from.
	/// @return True if successful, false if something went wrong.
	bool loadMacros(Configuration const* config);


};

}}


