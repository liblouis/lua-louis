;; An example on how to invoke liblouis from fennel
;; see https://fennel-lang.org/

(let [louis (require :liblua-louis)]
  (print (louis.translateString "en-ueb-g2.ctb" "Hello World"))
  (print (louis.version)))
