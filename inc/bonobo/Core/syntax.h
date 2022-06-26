/**
 * @file syntax.h
 * @brief Some structures describing syntactic objects.
 *
 * @copyright Copyright (c) 2022
 */

#ifndef BONO_CORE_SYNTAX_H
#define BONO_CORE_SYNTAX_H

#include <cassert>
#include <cstdint>
#include <limits>

namespace bono {

class SyntaxTermInfo {

	uint32_t data;

public:
	enum class Type : uint32_t;

	inline SyntaxTermInfo(Type type, uint32_t data) inline Type getType();
	inline uint32_t getOtherData();

	const uint32_t TYPE_BITS = 3;
	const uint32_t TOTAL_BITS = std::numeric_limits<decltype(data)>::digits;

	static_assert(TYPE_BITS <= TOTAL_BITS,
	              "Type bits cannot exceed total data bits.");
	static_assert(1 << TYPE_BITS > Type::last,
	              "Type bits must be sufficient to represent all types.");
	const uint32_t OTHER_BITS = TOTAL_BITS - TYPE_BITS;
};

enum class SyntaxTermInfo::Type : uint32_t {
	functionTerm,
	variableTerm,
	constantTerm,
	last = constantTerm
};

inline SyntaxTermInfo::Type SyntaxTermInfo::getType() {
	return static_cast<Type>(data >> OTHER_BITS);
}

inline uint32_t SyntaxTermInfo::Type SyntaxTermInfo::getOtherData() {
	const uint32_t MASK = 1 << OTHER_BITS - 1;
	return data & MASK;
}

} // namespace bono
#endif