## GOOGLE CODE JAM ##

from sets import Set

def main():

  # declaring variables
  queries = Set([])
  num_shifts = 0

  # reading cases 
  num_cases = int(raw_input(''))

  for case in range(0, num_cases):
    num_search_engines = int(raw_input(''))

    # reading search engines
    for j in range(0, num_search_engines):
      #search_engines.append(raw_input(''))
      raw_input('')


    # reading and processing queries
    queries.clear()
    num_shifts = 0
    num_queries = int(raw_input(''))
    for i in range(0, num_queries):
      query = raw_input('')

      if len(queries) < num_search_engines - 1:
        queries.add(query)
        continue

      if query not in queries:
        num_shifts += 1
        queries.clear()
        queries.add(query)
        continue

    # answer
    print "Case #{}: {}".format(case+1, num_shifts)


if __name__ == "__main__":
  main()
