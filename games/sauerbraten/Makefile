# $OpenBSD: Makefile,v 1.11 2021/11/29 16:28:31 espie Exp $

ONLY_FOR_ARCHS=	i386 amd64 macppc

COMMENT-main=	sauerbraten client
COMMENT-data=	sauerbraten data
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sauerbraten/}

HOMEPAGE=	http://sauerbraten.org/
MAINTAINER=	Jonathan Gray <jsg@openbsd.org>

MULTI_PACKAGES=	-main -data

N=		sauerbraten
V=		20201227
PKGNAME=	${N}-${V}
DISTNAME=	${N}_2020_12_27_linux
EXTRACT_SUFX=	.tar.bz2

PKG_ARCH-data=	*

# zlib (code) + no modification (data)
PERMIT_PACKAGE=		no modify
PERMIT_DISTFILES=	Yes

WRKDIST=		${WRKDIR}/${N}/src
USE_GMAKE=		Yes
MAKE_ENV+=              CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"
NO_TEST=		Yes

RUN_DEPENDS-main +=	${BASE_PKGPATH},-data

LIB_DEPENDS-main=	devel/sdl2-mixer \
			devel/sdl2-image \
			net/enet
WANTLIB-main=		GL X11 SDL2 SDL2_image SDL2_mixer c enet m pthread \
			${COMPILER_LIBCXX} z

COMPILER =		base-clang ports-gcc base-gcc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sauer_client ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/sauer_server ${PREFIX}/libexec
	${SUBST_CMD} -m 555 -c ${FILESDIR}/sauerbraten.sh ${WRKSRC}/sauerbraten.sh
	${INSTALL_SCRIPT} ${WRKSRC}/sauerbraten.sh ${PREFIX}/bin/sauerbraten
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${N}
	cp -R ${WRKDIR}/${N}/docs/* ${PREFIX}/share/doc/${N}/
	@perl -pi -e s,docs/,, ${WRKDIR}/${N}/README.html
	${INSTALL_DATA} ${WRKDIR}/${N}/README.html ${PREFIX}/share/doc/${N}/
	${INSTALL_DATA_DIR} ${PREFIX}/share/${N}
	cp -R ${WRKDIR}/${N}/packages ${PREFIX}/share/${N}
	cp -R ${WRKDIR}/${N}/data ${PREFIX}/share/${N}

.include <bsd.port.mk>
