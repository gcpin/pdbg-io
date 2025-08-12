hwaccess_sources = files(
  'src/hwAccessIntf.C',
  'src/hwDirectAccess.C',
  'src/hwSbeAccess.C',
  'src/hwTransport.C',
)

hwaccess_inc = include_directories(
  'include', 
)

hwaccess_lib = shared_library(
  'hwaccess',
  hwaccess_sources,
  include_directories: hwaccess_inc,
  dependencies: targeting_dep,
  install: true
)
