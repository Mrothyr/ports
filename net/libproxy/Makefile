# $OpenBSD: Makefile,v 1.70 2021/11/02 00:01:39 sthen Exp $

COMMENT-main=		library handling all the details of proxy configuration
COMMENT-webkit=		pacrunner libproxy plugin for webkit-based browsers

GH_ACCOUNT=		libproxy
GH_PROJECT=		libproxy
GH_TAGNAME=		0.4.17
SUBST_VARS=		GH_TAGNAME

PKGNAME-main=		${DISTNAME}
PKGNAME-webkit=		${GH_PROJECT}-webkit-${GH_TAGNAME}
REVISION-main=		0
REVISION-webkit=	0

CATEGORIES=		net

SHARED_LIBS +=  proxy          1.1 # 0.0

HOMEPAGE=		https://libproxy.googlecode.com/

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# LGPLv2.1
PERMIT_PACKAGE=	Yes

# order matters: cmake must come before python
MODULES=		devel/cmake \
			lang/python

COMPILER =		base-clang ports-gcc base-gcc

# cyclic dependency: libproxy,-webkit -> webkit -> gtk+3|libsoup -> glib2-networking -> libproxy
PSEUDO_FLAVORS=		no_webkit bootstrap
FLAVOR?=		no_webkit bootstrap

MULTI_PACKAGES=		-main -webkit

BUILD_DEPENDS=		lang/vala

RUN_DEPENDS-main=	${MODPY_RUN_DEPENDS}
LIB_DEPENDS-main=	devel/glib2 \
			x11/dbus

RUN_DEPENDS-webkit=	# empty
LIB_DEPENDS-webkit=	STEM->=${GH_TAGNAME}:${BUILD_PKGPATH}, \
			www/webkitgtk4

WANTLIB += intl m ${COMPILER_LIBCXX}

WANTLIB-main += ${WANTLIB}
WANTLIB-main += c dbus-1 gio-2.0 glib-2.0 gobject-2.0 perl pthread
WANTLIB-main += perl # uses perl ABI

WANTLIB-webkit += ${WANTLIB}
WANTLIB-webkit += glib-2.0 gobject-2.0 javascriptcoregtk-4.0 proxy pthread

CONFIGURE_ENV=	LIBlibproxy_VERSION=${LIBproxy_VERSION}
MAKE_ENV=	LIBlibproxy_VERSION=${LIBproxy_VERSION}

CONFIGURE_ARGS=		-DCMAKE_C_FLAGS="${CFLAGS}" \
			-DCMAKE_CXX_FLAGS="${CXXFLAGS}" \
			-DWITH_PERL:BOOL=ON \
			-DPERL_LINK_LIBPERL:BOOL=ON \
			-DWITH_GNOME3:BOOL=ON \
			-DWITH_VALA:BOOL=ON \
			-DWITH_DOTNET:BOOL=OFF \
			-DWITH_NM:BOOL=OFF \
			-DWITH_MOZJS:BOOL=OFF \
			-DWITH_NATUS:BOOL=OFF \
			-DBIPR:BOOL=OFF

# before bsd.port.arch.mk
DEBUG_PACKAGES=		${BUILD_PACKAGES}

.include <bsd.port.arch.mk>
.if ${BUILD_PACKAGES:M-webkit}
CONFIGURE_ARGS +=	-DWITH_WEBKIT3:BOOL=ON
.else
CONFIGURE_ARGS +=	-DWITH_WEBKIT:BOOL=OFF
.endif

.include <bsd.port.mk>
