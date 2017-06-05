 #!/usr/bin/env bash

PAGES=(http://www.eriksarasmusic.com http://www.eriksarasmusic.com)

for PAGE in ${PAGES}; do echo $PAGE; curl $PAGE; sleep 10; done

echo done

exit 0

