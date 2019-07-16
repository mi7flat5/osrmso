from Router import Router

router = Router("/home/shane/CLionProjects/data/data.osrm")

data1 = [-80.86,35.21]
data2 = [-78.64,36.78]

print(router.do_route(data1,data2))