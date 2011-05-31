KIT := s60_30
CERT := dev

BASENAME := pybtswitch
VERSION := 1.01

-include local/custom.mk

bin :
	sake --trace kits=$(KIT) udeb=true logging=true cert=$(CERT)

bin-all :
	sake all release kits=s60_20
	sake all release kits=s60_30 cert=self
	sake all release kits=s60_30 cert=dev
