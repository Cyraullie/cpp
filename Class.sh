#!/usr/bin/env bash
# Générateur de classe C++ avec canonical form (sans namespace)

set -euo pipefail

if [ $# -lt 1 ]; then
echo "Usage: $0 NomClasse"
exit 1
fi

classname="$1"
header="${classname}.hpp"
source="${classname}.cpp"

# Guard pour éviter inclusion multiple
guard="$(echo "$classname" | tr '[:lower:]' '[:upper:]')_HPP"

# Vérification si les fichiers existent déjà
if [ -e "$header" ] || [ -e "$source" ]; then
echo "Erreur : $header ou $source existe déjà."
exit 1
fi

# Écriture du header
cat > "$header" <<EOF

#ifndef ${guard}
# define ${guard}

# include <string>
# include <iostream>
# include "colors.hpp"

class ${classname} {
	private:
		std::string _name;

	public:
		${classname}();										// Default constructor
		${classname}(std::string name);						// Data constructor
		${classname}(const ${classname}& cpy);				// Copy constructor
		${classname}& operator=(const ${classname}& src);	// Copy assignment
		~${classname}();									// Destructor

		// --- Example methods ---
		void setName(const std::string& name);
		const std::string& getName() const;

};

#endif // ${guard}
EOF

# Écriture du source
cat > "$source" <<EOF
#include "${header}"

// Default constructor
${classname}::${classname}() : _name("")
{
	std::cout << GREEN << "Default ${classname} constructor called" << RESET << std::endl;
}

// Data constructor
${classname}::${classname}(std::string name) : _name(name)
{
	std::cout << LIGHT_GREEN << " ${classname} constructor called for " << ITALIC << name << RESET << std::endl;
}

// Copy constructor
${classname}::${classname}(const ${classname}& cpy) : _name(cpy._name)
{
	std::cout << LIGHT_GREEN << " ${classname} copy constructor called for " << ITALIC << cpy._name << RESET << std::endl;
}

// Copy assignment
${classname}& ${classname}::operator=(const ${classname}& src)
{
	if (this != &src) {
		this->_name = src._name;
	}
	return *this;
}

// Destructor
${classname}::~${classname}()
{
	std::cout << RED << " ${classname} destructor called for " << ITALIC << this->_name << RESET << std::endl;
};

// Example methods
void ${classname}::setName(const std::string& name) 
{
	this->_name = name;
}

const std::string& ${classname}::getName() const 
{
	return this->_name;
}
EOF

echo "✅ Classe ${classname} générée : ${header} et ${source}"
