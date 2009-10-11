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
## along with this library.  If not, see <http://www.gnu.org/licenses/>.

check_PROGRAMS = dock
gdlmm_includes = -I$(top_builddir)/gdl $(if $(srcdir:.=),-I$(top_srcdir)/gdl)

AM_CPPFLAGS = -I$(top_builddir) $(gdlmm_includes) $(GDLMM_CFLAGS)
AM_CXXFLAGS = $(GDLMM_WXXFLAGS)

LDADD = $(GDLMM_LIBS) $(top_builddir)/gdl/gdlmm/libgdlmm-$(GDLMM_API_VERSION).la

dock_SOURCES = dock.cc
