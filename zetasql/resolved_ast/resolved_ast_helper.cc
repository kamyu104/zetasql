//
// Copyright 2019 ZetaSQL Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "zetasql/resolved_ast/resolved_ast_helper.h"

#include "zetasql/resolved_ast/resolved_ast.h"
#include "zetasql/resolved_ast/resolved_column.h"

namespace zetasql {

const ResolvedComputedColumn* FindProjectComputedColumn(
    const ResolvedProjectScan* project, const ResolvedColumn& column) {
  for (const auto& computed_column : project->expr_list()) {
    if (computed_column->column() == column) {
      return computed_column.get();
    }
  }
  return nullptr;
}

const ResolvedExpr* FindProjectExpr(
    const ResolvedProjectScan* project, const ResolvedColumn& column) {
  const ResolvedComputedColumn* computed_column =
      FindProjectComputedColumn(project, column);
  if (computed_column != nullptr) {
    return computed_column->expr();
  }
  return nullptr;
}

}  // namespace zetasql
