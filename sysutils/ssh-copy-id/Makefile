# $OpenBSD: Makefile,v 1.3 2022/01/25 14:26:57 kn Exp $

COMMENT=        script to copy one's SSH keys to remote hosts
V=              8.8p1
DISTNAME=       openssh-${V}
PKGNAME=        ssh-copy-id-${V:S/p/pl/}
CATEGORIES=     sysutils

HOMEPAGE=       http://git.hands.com/ssh-copy-id
MAINTAINER=     Jan-Piet Mens <ports@jpmens.net>

# License free to use
PERMIT_PACKAGE= Yes

MASTER_SITES=   https://cdn.openbsd.org/pub/OpenBSD/OpenSSH/portable/

NO_BUILD=	Yes
NO_TEST=	Yes
PKG_ARCH=	*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/ssh-copy-id ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/contrib/ssh-copy-id.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
