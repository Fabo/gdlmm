## Copyright (c) 2009  Fabien Parent <parent.f@gmail.com>
##
## This file is part of gdlmm.
##
## gdlmm is free software: you can redistribute it and/or modify it
## under the terms of the GNU Lesser General Public License as published
## by the Free Software Foundation, either version 2.1 of the License,
## or (at your option) any later version.
##
## gdlmm is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
## See the GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.

ACLOCAL_AMFLAGS = -I build ${ACLOCAL_FLAGS}
DISTCHECK_CONFIGURE_FLAGS = --enable-warnings=fatal

if MAINTAINER_MODE
src_subdirs = codegen gdl/src
else
src_subdirs =
endif
if ENABLE_DOCUMENTATION
doc_subdirs = doc
else
doc_subdirs =
endif
SUBDIRS = $(src_subdirs) gdl/gdlmm examples $(doc_subdirs)

gdlmm_includedir = $(includedir)/$(GDLMM_MODULE_NAME)
gdlmm_include_HEADERS = gdl/gdlmm.h
gdlmm_libincludedir = $(libdir)/$(GDLMM_MODULE_NAME)/include
nodist_gdlmm_libinclude_HEADERS = gdl/gdlmmconfig.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = gdl/$(GDLMM_MODULE_NAME).pc

dist_noinst_SCRIPTS = autogen.sh

include $(top_srcdir)/build/dist-changelog.am
