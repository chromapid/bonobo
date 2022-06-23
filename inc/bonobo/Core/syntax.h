/**
 * @file syntax.h
 * @brief Some structures describing syntactic objects.
 *
 * @copyright Copyright (c) 2022
 */

#include <cassert>
#include <cstdint>

namespace bono {

class SyntaxTerm {
	uint32_t data;

public:
	enum class Type;
	inline SyntaxTerm::Type SyntaxTerm::getType();
};

enum class SyntaxTerm::Type : uint32_t {};

inline SyntaxTerm::Type SyntaxTerm::getType() {
	assert(data >> (32 - 8) && "");
	return static_cast<Type>(data >> (32 - 8));
}

} // namespace bono