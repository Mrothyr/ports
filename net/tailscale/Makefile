# $OpenBSD: Makefile,v 1.8 2022/02/09 17:50:25 abieber Exp $

BROKEN-i386 =	unix.EPROTO not defined

COMMENT =	modern overlay-like VPN built on top of WireGuard

MODGO_MODNAME =	tailscale.com
MODGO_VERSION =	v1.20.4

DISTNAME =	tailscale.com-${MODGO_VERSION}
PKGNAME =	tailscale-${MODGO_VERSION:S/v//}

CATEGORIES =	net

HOMEPAGE =	https://tailscale.com/

MAINTAINER =	Aaron Bieber <abieber@openbsd.org>

# BSD-3
PERMIT_PACKAGE =	Yes

WANTLIB += c pthread

MODULES =		lang/go

WRKDIST =	${WRKSRC}

.include "modules.inc"

.include <bsd.port.mk>
