#ifndef FACTORY_H
#define FACTORY_H

#include <map>

// Template for the class Factory. The base class and the identifier type must be specified to instantiate.
template
<
class AbstractProduct,	//the base class of the hierarchy
typename IdentifierType,
typename ProductCreator = AbstractProduct* (*)() //the callable entity that creates objects
>

/**\brief General class Factory for creating objects of any class and type identifier
 *
 * 
 * Pattern design extracted from the book Modern c++ design (Andrei Alexandrescu)
 */
class Factory
{
public:
	/// Returns true if registration successful
	bool Register(const IdentifierType& id, ProductCreator creator)
	{
		return (associations_.insert(typename AssocMap::value_type(id,creator)) ).second;
	}
	/// Returns true if the typeidentifier was previously registered
	bool Unregister(const IdentifierType& id)
	{
		return associations_.erase(id) == 1;
	}
	/// Looks up for the type identifier in the map. If founded creates the object
	AbstractProduct* CreateObject(const IdentifierType& id)
	{
		typename AssocMap::const_iterator i = associations_.find(id);
		if(i != associations_.end())
		{
			return(i->second)();
		}	

		return NULL;
	}

	/// Singleton for instantiating a Factory of a concrete base class and identifier type
	static Factory& Instance()
	{
		static Factory<AbstractProduct, IdentifierType> myFactory;

		return myFactory;
	}

private:
	/// associations_ maps identifier types with the function that creates objects
	typedef std::map<IdentifierType, ProductCreator> AssocMap;
	AssocMap associations_;
};


#endif // FACTORY_H
