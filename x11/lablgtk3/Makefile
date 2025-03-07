# $OpenBSD: Makefile,v 1.10 2021/12/10 04:11:00 daniel Exp $

COMMENT =	OCaml interface to GTK+3
CATEGORIES =	x11 devel

V =		3.1.1
DISTNAME =	lablgtk3-${V}
REVISION =	3

MASTER_SITES =	https://github.com/garrigue/lablgtk/releases/download/${V}/
EXTRACT_SUFX =	.tbz

# LGPL
PERMIT_PACKAGE = Yes

WANTLIB += atk-1.0 c cairo cairo-gobject fontconfig freetype gdk-3
WANTLIB += gdk_pixbuf-2.0 gio-2.0 glib-2.0 gobject-2.0 gtk-3 gtksourceview-3.0
WANTLIB += harfbuzz intl m pango-1.0 pangocairo-1.0 pthread z

LIB_DEPENDS =	x11/gtk+3 \
		devel/gettext,-runtime \
		x11/gtksourceview3

RUN_DEPENDS =	graphics/ocaml-cairo

BUILD_DEPENDS = ${RUN_DEPENDS} \
		devel/dune \
		devel/dune,-configurator

USE_GMAKE =	Yes
MODULES =	lang/ocaml

CFLAGS +=	-fPIC

ALL_TARGET =	lablgtk3 lablgtk3-sourceview3

NO_TEST =	Yes

do-build:
	cd ${WRKSRC} && dune build -j ${MAKE_JOBS} -p lablgtk3,lablgtk3-sourceview3

do-install:
	cd ${WRKSRC} && dune install -j ${MAKE_JOBS} lablgtk3 lablgtk3-sourceview3

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/ocaml/lablgtk3
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/lablgtk3
	${INSTALL_DATA} ${WRKDIST}/README.md ${PREFIX}/share/doc/lablgtk3

.include <bsd.port.mk>
