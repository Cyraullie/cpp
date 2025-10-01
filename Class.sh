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
#include <utility> // std::move

class ${classname} {
public:
    // --- Canonical form (Rule of Five) ---
    ${classname}();                                // Default constructor
    ${classname}(const ${classname}& other);       // Copy constructor
    ${classname}& operator=(const ${classname}& other); // Copy assignment
    ${classname}(${classname}&& other) noexcept;   // Move constructor
    ${classname}& operator=(${classname}&& other) noexcept; // Move assignment
    ~${classname}();                               // Destructor

    // --- Example methods ---
    void setName(const std::string& name);
    const std::string& getName() const noexcept;

private:
    std::string name_;
};

#endif // ${guard}
EOF

# Écriture du source
cat > "$source" <<EOF
#include "${header}"

// Default constructor
${classname}::${classname}() : name_("") {}

// Copy constructor
${classname}::${classname}(const ${classname}& other) : name_(other.name_) {}

// Copy assignment
${classname}& ${classname}::operator=(const ${classname}& other) {
    if (this != &other) {
        name_ = other.name_;
    }
    return *this;
}

// Move constructor
${classname}::${classname}(${classname}&& other) noexcept : name_(std::move(other.name_)) {}

// Move assignment
${classname}& ${classname}::operator=(${classname}&& other) noexcept {
    if (this != &other) {
        name_ = std::move(other.name_);
    }
    return *this;
}

// Destructor
${classname}::~${classname}() = default;

// Example methods
void ${classname}::setName(const std::string& name) {
    name_ = name;
}

const std::string& ${classname}::getName() const noexcept {
    return name_;
}
EOF

echo "✅ Classe ${classname} générée : ${header} et ${source}"
