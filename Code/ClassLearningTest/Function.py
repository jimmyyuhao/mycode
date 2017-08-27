
class Function(object):
    name = ''
    calling_symbol_list = []
    called_symbol_list = []
    called_times = 0

    def __init__(self, func_name):
        self.name = func_name
        print 'Function %s is creating' %(self.name)

    def add_new_called_symbol_name_to_list(self, called_symbol_name):
        self.called_symbol_list += called_symbol_name

    def add_new_calling_function_name_to_list(self, calling_symbol_name):
        self.calling_symbol_list += calling_symbol_name


#####
if __name__ == '__main__':
    functions = C1Function('test')
    #####

