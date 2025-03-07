# $OpenBSD: Makefile,v 1.92 2021/11/28 11:42:25 ajacoutot Exp $

BROKEN-hppa=		libpt.so.7.0: undefined reference to __sync_fetch_and_or_4

COMMENT=		H.323 gatekeeper

V=			5.9
GH_ACCOUNT=		willamowius
GH_PROJECT=		gnugk
GH_TAGNAME=		v${V:S/./_/}
PKGNAME=		gnugk-${V}
REVISION=		0

CATEGORIES=		net telephony

HOMEPAGE=		http://www.gnugk.org/

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE=	Yes

WANTLIB += ${COMPILER_LIBCXX} c crypto curl h323 kvm lber ldap
WANTLIB += ldap_r lua5.2 m maxminddb netsnmp netsnmpagent netsnmpmibs
WANTLIB += pt sasl2 ssh ssl z

COMPILER=		base-clang ports-gcc base-gcc

MODULES=		lang/lua

# uses luaL_newlib, lua_setglobal
MODLUA_VERSION=5.2

BUILD_DEPENDS=		databases/mariadb \
			databases/postgresql

LIB_DEPENDS=		net/curl \
			net/h323plus \
			net/libmaxminddb \
			net/net-snmp \
			security/libssh

ALL_TARGET=		optshared
USE_GMAKE=		Yes
NO_TEST=		Yes

CONFIGURE_STYLE=	gnu

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib" \
			OPENH323DIR=${LOCALBASE}/include/openh323 \
			OPENH323MAKEDIR=${LOCALBASE}/share/openh323 \
			PTLIBDIR=${LOCALBASE}/share/ptlib

CONFIGURE_ARGS=		--disable-sqlite \
			--disable-unixodbc \
			--disable-mqtt \
			--disable-librabbitmq \
			--disable-redis \
			--with-pgsql-include-dir=${LOCALBASE}/include/postgresql \
			--with-lua-include-dir=${MODLUA_INCL_DIR} \
			--with-lua-lib-dir=${LOCALBASE}/lib

# http://www.tandberg.com/collateral/tandberg-ITU-license.pdf
# H.460.23/.24. Contact consulting@h323plus.org for licensing terms.
# (sync with net/h323plus)
CONFIGURE_ARGS +=	--disable-h46018
CONFIGURE_ARGS +=	--disable-h46023

MAKE_ENV=		VERBOSE=1
MAKE_FLAGS=		PT_LIBDIR=$$(pkg-config --variable libdir ptlib) \
			PTLIB_LIBDIR=$$(pkg-config --variable libdir ptlib) \
			OH323_LIBDIR=${LOCALBASE}/lib \
			OH323_INCDIR=${LOCALBASE}/include/openh323 \
			OBJDIR=.

DEBUG_PACKAGES=		${BUILD_PACKAGES}

pre-configure:
	sed -i.beforesubst 's,-llua,-llua${MODLUA_VERSION} -lm,g' \
		${WRKSRC}/configure

post-build:
	cd ${WRKSRC}/addpasswd && \
		${MAKE_ENV} PTLIBDIR=${LOCALBASE}/share/ptlib ${MAKE_PROGRAM} \
			${MAKE_FLAGS}

# gmake: *** No rule to make target 'install'.  Stop.
do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/gnugk ${PREFIX}/bin

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnugk/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gnugk/
	${INSTALL_MAN} ${WRKSRC}/docs/gnugk.1 ${PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${PREFIX}/share/doc/gnugk/
	cp ${WRKSRC}/etc/*.* ${PREFIX}/share/examples/gnugk/
	${INSTALL_PROGRAM} ${WRKSRC}/addpasswd/addpasswd ${PREFIX}/bin/addpasswd

.include <bsd.port.mk>
