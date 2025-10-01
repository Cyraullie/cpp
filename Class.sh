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
#pragma once
#ifndef ${guard}
#define ${guard}

#include <string>
#include <iostream>

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
	std::cout << "Default ${classname} constructor called" << std::endl;
}

// Data constructor
${classname}::${classname}(std::string name) : _name(name)
{
	std::cout << " ${classname} constructor called for " << name << std::endl;
}

// Copy constructor
${classname}::${classname}(const ${classname}& cpy) : _name(cpy._name)
{

}

// Copy assignment
${classname}& ${classname}::operator=(const ${classname}& src)
{
	if (this != &src) {
		_name = src._name;
	}
	return *this;
}

// Destructor
${classname}::~${classname}()
{
	std::cout << " ${classname} destructor called for " << this->_name << std::endl;
};

// Example methods
void ${classname}::setName(const std::string& name) 
{
	_name = name;
}

const std::string& ${classname}::getName() const 
{
	return _name;
}
EOF

echo "✅ Classe ${classname} générée : ${header} et ${source}"
