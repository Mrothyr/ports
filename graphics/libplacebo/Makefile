# $OpenBSD: Makefile,v 1.9 2022/02/13 13:07:05 sthen Exp $

COMMENT=	reusable library for GPU-accelerated video/image rendering

GH_ACCOUNT=	haasn
GH_PROJECT=	libplacebo
GH_TAGNAME=	v4.192.1
CATEGORIES=	graphics

SHARED_LIBS=	placebo	6.0

MAINTAINER=	Brad Smith <brad@comstyle.com>

# LGPLv2.1+
PERMIT_PACKAGE=	Yes

WANTLIB=	epoxy execinfo lcms2 m pthread

MODULES=	devel/meson

LIB_DEPENDS=	graphics/lcms2

COMPILER=	base-clang ports-gcc
COMPILER_LANGS=	c

CONFIGURE_ARGS+=-Ddefault_library=both \
		-Dd3d11=disabled \
		-Ddemos=false \
		-Dglslang=disabled \
		-Dshaderc=disabled \
		-Dunwind=disabled \
		-Dvulkan=disabled

.include <bsd.port.mk>
