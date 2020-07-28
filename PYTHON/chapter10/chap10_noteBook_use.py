from chap10_noteBook import Note
from chap10_noteBook import NoteBook

good_sentence = """세상 사는 데 도움이 되는 명언, 힘이되는 명언, 용기를 주는 명언,좋은 명언 모음100가지. 자주보면 좋을 것 같아 선별했습니다."""
note_1 = Note(good_sentence)

good_sentence = """삶이 있는 한 희망은 있다. - 키케로"""
note_2 = Note(good_sentence)

good_sentence = '''하루에 3시간을 걸으면 7년 후에 지구를 한 바퀴 돌 수 있다. -새뮤얼 존슨'''
note_3 = Note(good_sentence)

good_sentence = '''행복의 문이 하나 닫히면 다른 문이 열린다. 그러나 우리는 종종 닫힌 문을 멍하니바라보다가 우리를 향해 열린 문을 보지 못하게 된다. - 헬렌 켈러'''
note_4 = Note(good_sentence)

print(note_1)
note_1.remove()
print(note_1)

wise_saying_notebook = NoteBook('명언 노트')
wise_saying_notebook.add_note(note_1)
wise_saying_notebook.add_note(note_2)
wise_saying_notebook.add_note(note_3)
wise_saying_notebook.add_note(note_4)
print(wise_saying_notebook.get_number_of_all_pages())
print(wise_saying_notebook.get_number_of_all_characters())
wise_saying_notebook.remove_note(3)
print(wise_saying_notebook.get_number_of_all_pages())
wise_saying_notebook.add_note(note_4, 100)
wise_saying_notebook.add_note(note_4, 100)

for i in range(300):
    wise_saying_notebook.add_note(note_4, i)

print(wise_saying_notebook.get_number_of_all_pages())
for i in range(300):
    print(wise_saying_notebook.notes[i])
