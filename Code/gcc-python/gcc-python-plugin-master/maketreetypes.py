#   Copyright 2011 David Malcolm <dmalcolm@redhat.com>
#   Copyright 2011 Red Hat, Inc.
#
#   This is free software: you can redistribute it and/or modify it
#   under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful, but
#   WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#   General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see
#   <http://www.gnu.org/licenses/>.

from collections import namedtuple
from cpybuilder import camel_case

class TreeType(namedtuple('TreeType', 'SYM, STRING, TYPE, NARGS')):
    def camel_cased_string(self):
        return camel_case(self.STRING)

    # "type" seems to be an "enum_tree_code_class"; see GCC's tree.h

def iter_tree_types():
    import re
    f = open('autogenerated-tree-types.txt')
    for line in f:
        # e.g.
        #   ERROR_MARK, "error_mark", tcc_exceptional, 0
        m = re.match('(.+), (.+), (.+), (.+)', line)
        if m:
            yield TreeType(SYM=m.group(1),
                           STRING=m.group(2)[1:-1],
                           TYPE=m.group(3),
                           NARGS=int(m.group(4)))
        else:
            #    print 'UNMATCHED: ', line
            assert(line.startswith('#') or line.strip() == '')
    f.close()

class GimpleType(namedtuple('GimpleType', 'gimple_symbol printable_name gss_symbol')):
    def camel_cased_string(self):
        return camel_case(self.gimple_symbol)

def iter_gimple_types():
    import re
    f = open('autogenerated-gimple-types.txt')
    for line in f:
        # e.g.
        #   GIMPLE_ERROR_MARK, "gimple_error_mark", GSS_BASE
        m = re.match('(GIMPLE_.+), (.+), (.+)', line)
        if m:
            yield GimpleType(gimple_symbol=m.group(1),
                             printable_name=m.group(2)[1:-1],
                             gss_symbol=m.group(3))
        else:
            #    print 'UNMATCHED: ', line
            assert(line.startswith('#') or line.strip() == '' or line.startswith('GSS_'))
    f.close()


# Corresponds to a DEFGSTRUCT macro from gsstruct.def
class GimpleStructType(namedtuple('GimpleStructType', 'enum_value struct_name has_tree_operands')):
    def camel_cased_string(self):
        return camel_case(self.struct_name)

def iter_gimple_struct_types():
    import re
    f = open('autogenerated-gimple-types.txt')
    for line in f:
        # e.g.
        #   GSS_BASE, gimple_statement_base, false
        m = re.match('(GSS_.+), (.+), (.+)', line)
        if m:
            yield GimpleStructType(enum_value=m.group(1),
                                   struct_name=m.group(2),
                                   has_tree_operands=m.group(3))
        else:
            #    print 'UNMATCHED: ', line
            assert(line.startswith('#') or line.strip() == '' or line.startswith('GIMPLE_'))
    f.close()

# Corresponds to a DEF_RTL_EXPR macro from rtl.def
class DefRtlExpr(namedtuple('DefRtlExpr', 'ENUM, NAME, FORMAT, CLASS')):
    def camel_cased_string(self):
        return 'Rtl' + camel_case(self.ENUM)

def iter_rtl_expr_types():
    import re
    f = open('autogenerated-rtl-types.txt')
    for line in f:
        # e.g.
        #   rtl_expr: DEBUG_EXPR, "debug_expr", "0", RTX_OBJ
        m = re.match('rtl_expr: (.+), "(.+)", (.*), (.+)', line)
        if m:
            #print m.groups()
            yield DefRtlExpr(ENUM=m.group(1),
                             NAME=m.group(2),
                             FORMAT=m.group(3),
                             CLASS=m.group(4))
        else:
            #print 'UNMATCHED: %r' % line
            assert(line.startswith('#') or line.strip() == '' or line.startswith('GIMPLE_'))
    f.close()