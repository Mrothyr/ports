# $OpenBSD: Makefile,v 1.98 2021/11/02 00:01:54 sthen Exp $

PORTROACH=	skipv:2.3.x

COMMENT=	graphical frontend for LaTeX (nearly WYSIWYG)

DISTNAME=	lyx-2.3.6.1
REVISION=	0

CATEGORIES=	print editors

HOMEPAGE=	https://www.lyx.org/

MAINTAINER=	Elias M. Mariani <marianielias@gmail.com>

MASTER_SITES=	https://ftp.lip6.fr/pub/lyx/stable/2.3.x/ \
		http://ftp.icm.edu.pl/packages/lyx/stable/ \
		http://mirror.ufs.ac.za/applications/lyx/stable/2.3.x/ \
		ftp://ftp.lyx.org/pub/lyx/stable/2.3.x/ \
		ftp://ftp.ntua.gr/pub/X11/LyX/stable/2.3.x/ \
		ftp://ftp.u-aizu.ac.jp/pub/tex/lyx/stable/2.3.x/

WANTLIB+= ${COMPILER_LIBCXX} Qt5Concurrent Qt5Core Qt5Gui Qt5Svg
WANTLIB+= Qt5Widgets Qt5X11Extras aspell c enchant-2 hunspell-1.7
WANTLIB+= iconv m magic xcb z

COMPILER=	base-clang ports-gcc

# GPLv2+
PERMIT_PACKAGE=	Yes

MODULES=	lang/python \
		x11/qt5

BUILD_DEPENDS=	devel/boost
TEST_DEPENDS=	devel/boost

RUN_DEPENDS=	print/texlive/base \
		graphics/ImageMagick \
		x11/gtk+3,-guic \
		devel/desktop-file-utils

LIB_DEPENDS=	devel/libmagic \
		textproc/enchant2 \
		textproc/aspell/core \
		textproc/hunspell \
		x11/qt5/qtsvg \
		x11/qt5/qtx11extras

USE_GMAKE=	Yes

CONFIGURE_STYLE=		gnu

CONFIGURE_ARGS=	--with-extra-lib="${X11BASE}/lib ${LOCALBASE}/lib" \
		--with-extra-inc="${X11BASE}/include ${LOCALBASE}/include" \
		--enable-qt5 \
		--without-included-boost \
		--with-packaging=posix

CONFIGURE_ENV+=	PYTHON=${MODPY_BIN} \
		lyx_cv_callstack_printing=no \
		ac_cv_func_fork=yes LIBS=-pthread

pre-configure:
	sed -i "s,python -tt,${MODPY_BIN} -tt," \
		${WRKSRC}/src/support/os.cpp
	perl -pi -e "s,#! ?/usr/bin/(env )?python,#!${MODPY_BIN}," \
		${WRKSRC}/lib/lyx2lyx/lyx2lyx \
		${WRKSRC}/lib/scripts/listerrors \
		${WRKSRC}/src/graphics/GraphicsConverter.cpp
	find ${WRKSRC} -name "*.py" -exec \
		perl -pi -e "s,#! ?/usr/bin/(env )?python,#!${MODPY_BIN}," {} +

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/lyx/configure.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/lyx/scripts

.include <bsd.port.mk>
