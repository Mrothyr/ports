# $OpenBSD: Makefile,v 1.4 2021/08/31 15:17:58 fcambus Exp $

COMMENT =	collection of CLI tools for ARM devices with Allwinner SoCs

GH_ACCOUNT =	linux-sunxi
GH_PROJECT =	sunxi-tools
GH_TAGNAME =	v1.4
REVISION =	1

CATEGORIES =	sysutils
HOMEPAGE =	https://linux-sunxi.org/Sunxi-tools
# GPLv2+
PERMIT_PACKAGE =	Yes

USE_GMAKE =		Yes
WANTLIB =		c pthread usb-1.0
LIB_DEPENDS =		devel/libusb1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fel-gpio ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sunxi-bootinfo ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sunxi-fel ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sunxi-fexc ${PREFIX}/bin
	ln -s sunxi-fexc ${PREFIX}/bin/bin2fex
	ln -s sunxi-fexc ${PREFIX}/bin/fex2bin
	${INSTALL_PROGRAM} ${WRKSRC}/sunxi-nand-part ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sunxi-pio ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sunxi-tools
	${INSTALL_DATA} ${WRKSRC}/README.md ${PREFIX}/share/examples/sunxi-tools

.include <bsd.port.mk>
