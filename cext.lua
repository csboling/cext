local cextpath = paths.code..'cext'
print('compiling. output:')
print(util.os_capture('cd '..cextpath..' && make'))
print('////////')
local extpath = cextpath..'/test.so'
local test = package.loadlib(extpath, 'luaopen_test')()

function init()
  print('init')
  print('3 + 5 = '..test.sum2(3, 5))
end
