/*
	This file is part of solidity.

	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#include "UpgradeChange.h"
#include "UpgradeSuite.h"

#include <libsolidity/ast/ASTVisitor.h>

namespace dev
{
namespace solidity
{
namespace tools
{

/**
 * Module that performs analysis on the AST. It visits all contract
 * definitions and its defined functions and reports a source upgrade,
 * if one of the declared functions is the constructor but does not
 * use the `constructor` keyword.
 */
class ConstructorKeyword: public AnalysisUpgrade {
public:
	using AnalysisUpgrade::AnalysisUpgrade;

	void analyze(SourceUnit const& _sourceUnit) { _sourceUnit.accept(*this); }
private:
	void endVisit(ContractDefinition const& _contract);
};

/**
 * Module that performs analysis on the AST. It visits function definitions
 * and reports a source upgrade, if this function's visibility is `public`,
 * but not marked explicitly as such.
 */
class VisibilitySpecifier: public AnalysisUpgrade {
public:
	using AnalysisUpgrade::AnalysisUpgrade;

	void analyze(SourceUnit const& _sourceUnit) { _sourceUnit.accept(*this); }
private:
	void endVisit(FunctionDefinition const& _function);
};

}
}
}
